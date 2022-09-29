/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas
 * @author Jaime Armas Rivero
 * @since May 23 2022
 * @description Card Storage class
 *       Represents an abstract class that store cards and have methods to
 *       interact with them
 * @module card-storage
 * @see {@link https://en.wikipedia.org/wiki/French-suited_playing_cards}
 */

import { Card } from './card.js';

/**
 * Store cards and have methods to interact with them
 */
export abstract class CardStorage {
  /** List of the cards inside the storage */
  protected cardList: Card[] = [];

  /**
   * Get the cards of the storage
   * @return List of cards of the storage
   */
  getCards(): Card[] {
    return this.cardList;
  }

  /**
   * Get the amount of cards of the storage
   * @return Amount of cards
   */
  getLength(): number {
    return this.cardList.length;
  }

  /**
   * Delete a card from the storage and return it
   * @param card Card to pop from the storage
   * @return Card that have been deleted from the list or null if is not in the
   * list
   */
  popCard(card: Card): Card | null {
    for (let i = 0; i < this.cardList.length; ++i) {
      if (this.cardList[i].equals(card)) {
        return this.cardList.splice(i, 1)[0];
      }
    }
    return null;
  }

  /**
   * Add a card or more to the storage
   * @param cards Cards to add to the storage
   */
  addCards(cards: Card | Card[]): void {
    if (Array.isArray(cards)) this.cardList.push(...cards);
    else this.cardList.push(cards);
  }

  /**
   * Move an amount of cards to an storage
   * @param storageToMove Storage to move the cards
   * @param amount Amount of cards to move
   */
  moveCards(storageToMove: CardStorage, amount: number): void {
    const cappedAmount = Math.min(amount, this.cardList.length);
    storageToMove.addCards(this.cardList.splice(0, cappedAmount));
  }
}
