/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas
 * @author Jaime Armas Rivero
 * @since May 23 2022
 * @description Hand class
 *       Represents an hand of cards of the French-suited cards
 * @module hand
 * @see {@link https://en.wikipedia.org/wiki/French-suited_playing_cards}
 */

import { CardStorage } from './card-storage.js';

/** Hand of cards of the French-suited cards */
export class Hand extends CardStorage {
  /**
   * Construct an empty hand with a label
   * @param label Label that identify the hand
   */
  constructor(private label: string = '') {
    super();
  }

  /**
   * Get the label that identify the hand
   * @return Label of the hand
   */
  getLabel(): string {
    return this.label;
  }
}
