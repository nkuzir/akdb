/**
@file filesearch.h Header file provides data structures for file searching
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

#ifndef FILESEARCH
#define FILESEARCH

#include "../auxi/test.h"
#include "../mm/memoman.h"
#include "files.h"
#include "../auxi/mempro.h"

#define SEARCH_NULL       0
#define SEARCH_ALL        1
#define SEARCH_PARTICULAR 2
#define SEARCH_RANGE      3

/**
 * @author Unknown
 * @struct search_params
 * @brief Structure that contains attribute name, lower and upper data value, special(NULL or *) which is input for AK_equisearch_unsorted and  		AK_rangesearch_unsorted
 */
typedef struct {
    /// name of attribute
    char *szAttribute;
    /// pointer to lower value of search range
    void *pData_lower;
    /// pointer to upper value of search range
    void *pData_upper;
    /// if searching for NULL values, set to SEARCH_NULL, all values -> SEARCH_ALL, particular value -> SEARCH_PARTICULAR, range of values -> SEARCH_RANGE
    int iSearchType;
} search_params;

/**
  * @author Unknown
  * @struct search_result
  * @brief Structure which represents search result of AK_equisearch_unsorted and AK_rangesearch_unsorted
 */
typedef struct {
    /// array of tuple addresses
    int *aiTuple_addresses;
    /// array of blocks to which the tuple addresses are relative
    int *aiBlocks;
    /// number of tuple addresses/blocks in corresponding arrays
    int iNum_tuple_addresses;
    /// array of indexes of searched-for attributes
    int *aiSearch_attributes;
    /// number of searched-for attributes in array
    int iNum_search_attributes;
    /// number of attributes in tuple
    int iNum_tuple_attributes;
} search_result;



search_result AK_search_unsorted(char *szRelation, search_params *aspParams, int iNum_search_params);
void AK_deallocate_search_result(search_result srResult);
TestResult Ak_filesearch_test();

#endif
