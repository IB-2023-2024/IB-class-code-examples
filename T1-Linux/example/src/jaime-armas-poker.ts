/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas
 * @author Jaime Armas Rivero
 * @since May 14 2022
 * @description Poker in html with strategy MVC
 *       Poker application to check who win between two hands
 */

'use strict';

import { Controller } from './controller.js';
import { Model } from './model.js';
import { View } from './view.js';

/** Main program of the application */
const main = (): void => {
  const app: Controller = new Controller(new Model(), new View());
};

main();
