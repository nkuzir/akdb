/**
@file auxiliary.h Header file zhat provides data structures for the auxiliary functions
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

#ifndef AUXILIARY
#define AUXILIARY

#include "assert.h"
#include "time.h"
#include "string.h"
#include "ctype.h"
#include "debug.h"
#include "configuration.h"
#include "iniparser/iniparser.h"

/**
 * @author Unknown
 * @struct list_elem
 * @brief Structure defines a list element. Every list_elem has its type, size, data and name of column which it belongs
 */
struct list_elem {
    ///data type
    int type;
    //data size in list element
    int size;
    ///loaded data
    char data[ MAX_VARCHAR_LENGTH ];
    //table name
    char table[ MAX_ATT_NAME ];
    //attribute name
	char attribute_name[ MAX_ATT_NAME ];
	int constraint; //if 0 then it is new data for insertion, if 1 then it is a constraint on which update and delete searches the data
    ///pointer to next element
    struct list_elem *next;
};

typedef struct list_elem AK_list;
typedef struct list_elem *AK_list_elem;

#define TBL_BOX_OFFSET 1
//#define TBL_COL_DELIMITER '|'
//#define TBL_ROW_DELIMITER '-'

/*
enum tbl_valalign {
        ALIGN_LEFT  0,
        ALIGN_RIGHT 1;
};*/

int AK_strcmp(const void *a, const void *b);

/**
 * @author Frane Jakelić
 * @struct Vertex
 * @brief Structure defines a Vertex node element. Every Vertex has its VertexId, index, lowLink and pointer to next edge and vertex
 */
struct Vertex{
    int vertexId;
    int index;
    int lowLink;
    struct Succesor *nextSuccesor;
    struct Vertex *nextVertex;
};

/**
 * @author Frane Jakelić
 * @struct Succesor
 * @brief Structure defines a Succesor  element. Every Succesor has its Vertex pointer and pointer to next Succesor in the linked list
 */
struct Succesor{
	struct Vertex *link;
	struct Succesor *nextSuccesor;
};

/**
 * @author Frane Jakelić
 * @struct Stack
 * @brief Structure defines a Stack element. Every Stack has its Vertex pointer and pointer to next Stack in the linked list
 */
struct Stack{
	struct Vertex *link;
	struct Stack *nextElement;
};

typedef struct Vertex AK_graph;
typedef struct Succesor *AK_succesor;
typedef struct Vertex *AK_vertex;
typedef struct Stack *AK_stack;
typedef struct Stack AK_stackHead;


#endif

