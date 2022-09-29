/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas
 * @author Jaime Armas Rivero
 * @since Apr 30 2022
 * @description Jest configuration
 * @see {@link https://jestjs.io/es-ES/docs/next/configuration}
 */

'use strict';

import type { Config } from '@jest/types';

const config: Config.InitialOptions = {
  // collectCoverage: true,
  collectCoverageFrom: ['src/**/*.ts', '!src/app.ts'],
  coverageDirectory: 'coverage',
  coverageReporters: ['html', 'text'],
  rootDir: '.',
  coveragePathIgnorePatterns: ['node_modules'],
  transform: {},
  preset: 'ts-jest',
  testEnvironment: 'node',
};

export default config;
