/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas
 * @author Jaime Armas Rivero
 * @since May 23 2022
 * @description Deck class
 *       Represents a deck of 52 French-suited cards
 * @module deck
 * @see {@link https://en.wikipedia.org/wiki/French-suited_playing_cards}
 */

'use strict';

import { CardStorage } from './card-storage.js';
import { Card, Rank, Suit } from './card.js';
import { Hand } from './hand.js';
import { getEnumValues } from './utils.js';

/** Deck of 52 French-suited cards that can interact with hands */
export class Deck extends CardStorage {
  /** Construct a deck 52 cards French-suited cards */
  constructor() {
    super();
    const suitValues: number[] = getEnumValues(Suit);
    const rankValues: number[] = getEnumValues(Rank);
    for (const suit of suitValues) {
      for (const rank of rankValues) {
        this.cardList.push(new Card(suit, rank));
      }
    }
  }

  /**
   * Randomly shuffle the cards of the deck
   */
  shuffle(): void {
    for (let i = this.cardList.length - 1; i > 0; --i) {
      const index = Math.floor(Math.random() * (i + 1));
      [this.cardList[i], this.cardList[index]] = [
        this.cardList[index],
        this.cardList[i],
      ];
    }
  }

  /** Sort the cards of the deck from lower to highert */
  sort(): void {
    this.cardList.sort(
      (firstCard, secondCard) => Number(!firstCard.compare(secondCard)) * -1
    );
  }

  /**
   * Deal a number of hands with a number of cards each one
   * @param handsAmount Number of hands to deal
   * @param cardsAmount Number of cards for each hand
   * @return Hands list
   */
  dealHands(handsAmount: number, cardsAmount: number): Hand[] {
    const hands: Hand[] = [];
    for (let i = 0; i < handsAmount; ++i) {
      const hand: Hand = new Hand();
      this.moveCards(hand, cardsAmount);
      hands.push(hand);
    }
    return hands;
  }
}
