/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas
 * @author Jaime Armas Rivero
 * @since May 22 2022
 * @description Web Server App
 *       Express app for show apps output, docs and coverage
 */

'use strict';

import express from 'express';
import type { Express } from 'express';
import path from 'path';

const app: Express = express();

const PORT = 8080;
app.set('port', PORT);

app.use(express.static(path.join(__dirname, 'public')));
app.use('/docs', express.static(path.join(__dirname, '../docs')));
app.use('/coverage', express.static(path.join(__dirname, '../coverage')));
app.use('/dist', express.static(path.join(__dirname, '../dist')));

app.listen(PORT, '0.0.0.0', () => {
  console.log(`The server is running on http://10.6.129.67:${PORT}`);
});
