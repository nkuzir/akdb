/**
@file between.h Header file that provides data structures for between constaint
 */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor Boston, MA 02110-1301,  USA
 */

#ifndef BETWEEN
#define BETWEEN

#include "../../auxi/test.h"
#include "../../mm/memoman.h"
#include "../../file/id.h"
#include "../../auxi/mempro.h"

int AK_find_table_address(char *_systemTableName);
void AK_set_constraint_between(char* tableName, char* constraintName, char* attName, char* startValue, char* endValue);
int AK_read_constraint_between(char* tableName, char* newValue, char* attNamePar);
int AK_delete_constraint_between(char* tableName, char attName[], char constraintName[]);
TestResult Ak_constraint_between_test();

#endif
