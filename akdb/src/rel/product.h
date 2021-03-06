/**
@file product.h Header file that provides data structures for relational product operation
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

#ifndef PRODUCT
#define PRODUCT

#include "../auxi/test.h"
#include "../file/table.h"
#include "../file/files.h"
#include "../auxi/mempro.h"
#include "../sql/drop.h"


int AK_product(char *srcTable1, char * srcTable2, char * dstTable);
void AK_product_procedure(char *srcTable1, char * srcTable2, char * dstTable, AK_header header[MAX_ATTRIBUTES]);
TestResult AK_op_product_test();

#endif

