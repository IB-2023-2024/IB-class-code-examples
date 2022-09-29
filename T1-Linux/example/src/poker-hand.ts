/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas
 * @author Jaime Armas Rivero
 * @since May 23 2022
 * @description Poker Hand class
 *       Represents an hand of cards of the French-suited cards in poker
 * @module poker-hand
 * @see {@link https://en.wikipedia.org/wiki/French-suited_playing_cards}
 */

import { Rank, Suit } from './card.js';
import { Hand } from './hand.js';
import { getEnumValues } from './utils.js';

/** Interface with the score of the hand and the name of the best play */
export interface PokerHandClassification {
  score: number;
  tag: string;
}

/** Hand of cards of the French-suited cards in poker */
export class PokerHand extends Hand {
  /**
   * Convert a Hand to a Pokerhand
   * @param hand Hand to convert
   * @return Hand converted to PokerHand
   */
  static fromHand(hand: Hand): PokerHand {
    const pokerHand = new PokerHand();
    Object.assign(pokerHand, hand);
    return pokerHand;
  }

  /**
   * Get a map with the amount of cards for each rank
   * @return Map with the amount of cards for each rank
   */
  private getRanksAmount(): Map<Rank, number> {
    const ranksAmount: Map<Rank, number> = new Map();
    for (const card of this.cardList) {
      const rank = card.getRank();
      ranksAmount.set(rank, (ranksAmount.get(rank) ?? 0) + 1);
    }
    return ranksAmount;
  }

  /**
   * Get a map with the amount of cards for each suit
   * @return Map with the amount of cards for each suit
   */
  private getSuitsAmount(): Map<Suit, number> {
    const suitsAmount: Map<Suit, number> = new Map();
    for (const card of this.cardList) {
      const suit = card.getSuit();
      suitsAmount.set(suit, suitsAmount.get(suit) ?? 0 + 1);
    }
    return suitsAmount;
  }

  /**
   * Get a map with the suits for each rank
   * @return Map with the suits for each rank
   */
  private getRanksSuits(): Map<Rank, Set<Suit>> {
    const ranksSuits: Map<Rank, Set<Suit>> = new Map();
    for (const card of this.cardList) {
      const rank = card.getRank();
      ranksSuits.set(
        rank,
        (ranksSuits.get(rank) ?? new Set<Suit>()).add(card.getSuit())
      );
    }
    return ranksSuits;
  }

  /**
   * Compute if the hand has a pair of cards
   * @return If the hand has a pair
   */
  hasPair(): boolean {
    const ranksAmount: Map<Rank, number> = this.getRanksAmount();
    const rankValues: Rank[] = getEnumValues(Rank);
    for (const rank of rankValues) {
      if ((ranksAmount.get(rank) ?? 0) === 2) return true;
    }
    return false;
  }

  /**
   * Compute if the hand has two pair of cards
   * @return If the hand has two pair
   */
  hasTwoPair(): boolean {
    const ranksAmount: Map<Rank, number> = this.getRanksAmount();
    const rankValues: Rank[] = getEnumValues(Rank);
    let pairsAmount = 0;
    for (const rank of rankValues) {
      if ((ranksAmount.get(rank) ?? 0) === 2) ++pairsAmount;
    }
    return pairsAmount === 2;
  }

  /**
   * Compute if the hand has three cards with the same value
   * @return If the hand has two pair three of a kind
   */
  hasThreeKind(): boolean {
    const ranksAmount: Map<Rank, number> = this.getRanksAmount();
    const rankValues: Rank[] = getEnumValues(Rank);
    for (const rank of rankValues) {
      if ((ranksAmount.get(rank) ?? 0) === 3) return true;
    }
    return false;
  }

  /**
   * Compute if the hand has five cards in sequence
   * @return If the hand has straight
   */
  hasStraight(): boolean {
    const ranksAmount: Map<Rank, number> = this.getRanksAmount();
    const rankValues: Rank[] = getEnumValues(Rank);
    rankValues.push(Rank.ACE);
    let sequenceCount = 0;
    for (const rank of rankValues) {
      if ((ranksAmount.get(rank) ?? 0) > 0) {
        ++sequenceCount;
        if (sequenceCount === 5) return true;
      } else {
        sequenceCount = 0;
      }
    }
    return false;
  }

  /**
   * Compute if the hand has five cards with same suit
   * @return If the hand has flush
   */
  hasFlush(): boolean {
    const suitsAmount: Map<Suit, number> = this.getSuitsAmount();
    const suitValues: Suit[] = getEnumValues(Suit);
    for (const suit of suitValues) {
      if ((suitsAmount.get(suit) ?? 0) === 5) return true;
    }
    return false;
  }

  /**
   * Compute if the hand has three cards with same value and two cards with another
   * @return If the hand has full house
   */
  hasFullHouse(): boolean {
    return this.hasPair() && this.hasThreeKind();
  }

  /**
   * Compute if the hand has four cards with same rank
   * @return If the hand has four of a kind
   */
  hasFourKind(): boolean {
    const ranksAmount: Map<Rank, number> = this.getRanksAmount();
    const rankValues: Rank[] = getEnumValues(Rank);
    for (const rank of rankValues) {
      if ((ranksAmount.get(rank) ?? 0) === 4) return true;
    }
    return false;
  }

  /**
   * Compute if the hand has five cars in sequence and with the same suit
   * @return If the hand has straight flush
   */
  hasStraightFlush(): boolean {
    const ranksSuits: Map<Rank, Set<Suit>> = this.getRanksSuits();
    const rankValues: Rank[] = getEnumValues(Rank);
    rankValues.push(Rank.ACE);
    let suitsSequence = new Set<Suit>([
      Suit.CLUBS,
      Suit.DIAMONDS,
      Suit.HEARTS,
      Suit.SPADES,
    ]);
    let sequenceCount = 0;
    for (const rank of rankValues) {
      const rankSuits: Set<Suit> = ranksSuits.get(rank) ?? new Set<Suit>();
      for (const suit of suitsSequence) {
        if (!rankSuits.has(suit)) suitsSequence.delete(suit);
      }
      if (suitsSequence.size > 0) {
        ++sequenceCount;
        if (sequenceCount === 5) return true;
      } else {
        suitsSequence = rankSuits;
        sequenceCount = suitsSequence.size > 0 ? 1 : 0;
      }
    }
    return false;
  }

  /**
   * Get the hightest card of the hand
   * @return Hightest card
   */
  getMaxRank(): number {
    let bestRank = 0;
    for (const card of this.cardList) {
      if (card.getRank() > bestRank) bestRank = card.getRank();
    }
    return bestRank;
  }

  /**
   * Get the best play that the hand has
   * @return Best play with score and name
   */
  classify(): PokerHandClassification {
    if (this.hasPair()) return { score: 1, tag: 'Pair' };
    if (this.hasTwoPair()) return { score: 2, tag: 'Two Pair' };
    if (this.hasThreeKind()) return { score: 3, tag: 'Three of a Kind' };
    if (this.hasStraight()) return { score: 4, tag: 'Straight' };
    if (this.hasFlush()) return { score: 5, tag: 'Flush' };
    if (this.hasFullHouse()) return { score: 6, tag: 'Full House' };
    if (this.hasFourKind()) return { score: 7, tag: 'Four of a Kind' };
    if (this.hasStraightFlush()) return { score: 8, tag: 'Straight Flush' };
    return { score: 0, tag: 'High Card' };
  }
}
