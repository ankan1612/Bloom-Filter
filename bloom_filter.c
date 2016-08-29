/* 
---------------------------------------------------------------------------------------------------------
Solution to the 4th Project of Advanced Data Structures I9600
City College of New York, CUNY 

AUTHOR : ANKAN KUMAR GIRI

Email : agiri000@citymail.cuny.edu / ankangiri@gmail.com
---------------------------------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXP 2147483647
typedef struct htp_l_node 
{ 
    int a; 
    struct htp_l_node *next; 
} htp_l_node_t; 
typedef struct 
{ 
    int b;   
    struct htp_l_node *a_list;
} hf_param_t;
typedef struct 
{ 
    char **table;                 
    int (*hash_function)(char *, hf_param_t *); 
    hf_param_t **hf_param; 
} bloomfilter_t;
int universalhashfunction(char *key, hf_param_t *hfp)
{  
    int sum;
    htp_l_node_t *al;
    sum = hfp->b;
    al = hfp->a_list;
    while( *key != '\0' )
    {  
        if( al->next == NULL )
        {   
            al->next = (htp_l_node_t *) malloc(sizeof(htp_l_node_t));
            al->next->next = NULL;
            al->a = rand()%MAXP;
        }
        sum += ( (al->a)*((int) *key))%MAXP;
        key += 1;
        al = al->next;
    }
    return( sum%2000000 );
}
bloomfilter_t *create_bf()
{   
    bloomfilter_t *tmp;
    int i;
    int universalhashfunction(char *, hf_param_t *);
    tmp = (bloomfilter_t*) malloc(sizeof(bloomfilter_t));
    tmp->table = (char **)malloc(sizeof(char) * 8 * sizeof(char *));
    tmp->hf_param = (hf_param_t **) malloc(sizeof(char) * 8 * sizeof(hf_param_t*));
    for(i=0; i<sizeof(char)*8; i++)
    {
        (tmp->table)[i] = (char*) malloc(sizeof(char) * 250000 * sizeof(char));
        (tmp->hf_param)[i] = (hf_param_t*) malloc(sizeof(hf_param_t));
        (tmp->hf_param)[i]->b = rand()%MAXP;
        (tmp->hf_param)[i]->a_list = (htp_l_node_t *)malloc(sizeof(htp_l_node_t));
        (tmp->hf_param)[i]->a_list->next = NULL;
    }
    tmp->hash_function = universalhashfunction;
    return( tmp );
}
void insert_bf(bloomfilter_t *bf, char *new_key)
{  
    int i, hash; 
    for(i=0; i<sizeof(char)*8; i++)
    {
        hash = abs(bf->hash_function(new_key, bf->hf_param[i]));
        bf->table[i][hash/8] = bf->table[i][hash/8] | (1<<hash%8);
    }
}
int is_element(bloomfilter_t *bf, char *new_key) 
{
    int i, hash;
    int accepted = 1;
    for(i=0; i<sizeof(char)*8; i++)
    {
        hash = abs(bf->hash_function(new_key, bf->hf_param[i]));
        if(!(bf->table[i][hash/8] & 1<<hash%8))
        {
            accepted = 0;
            break;
        }
    }
    return accepted;
}    
void sample_string_A(char *s, long i)
{  s[0] = (char)(1 + (i%254));
   s[1] = (char)(1 + ((i/254)%254));
   s[2] = (char)(1 + (((i/254)/254)%254));
   s[3] = 'a';
   s[4] = 'b';
   s[5] = (char)(1 + ((i*(i-3)) %217));
   s[6] = (char)(1 + ((17*i+129)%233 ));
   s[7] = '\0';
}
void sample_string_B(char *s, long i)
{  s[0] = (char)(1 + (i%254));
   s[1] = (char)(1 + ((i/254)%254));
   s[2] = (char)(1 + (((i/254)/254)%254));
   s[3] = 'a';
   s[4] = (char)(1 + ((i*(i-3)) %217));
   s[5] = (char)(1 + ((17*i+129)%233 ));
   s[6] = '\0';
}
void sample_string_C(char *s, long i)
{  s[0] = (char)(1 + (i%254));
   s[1] = (char)(1 + ((i/254)%254));
   s[2] = 'a';
   s[3] = (char)(1 + ((i*(i-3)) %217));
   s[4] = (char)(1 + ((17*i+129)%233 ));
   s[5] = '\0';
}
void sample_string_D(char *s, long i)
{  s[0] = (char)(1 + (i%254));
   s[1] = (char)(1 + ((i/254)%254));
   s[2] = (char)(1 + (((i/254)/254)%254));
   s[3] = 'b';
   s[4] = 'b';
   s[5] = (char)(1 + ((i*(i-3)) %217));
   s[6] = (char)(1 + ((17*i+129)%233 ));
   s[7] = '\0';
}
void sample_string_E(char *s, long i)
{  s[0] = (char)(1 + (i%254));
   s[1] = (char)(1 + ((i/254)%254));
   s[2] = (char)(1 + (((i/254)/254)%254));
   s[3] = 'a';
   s[4] = (char)(2 + ((i*(i-3)) %217));
   s[5] = (char)(1 + ((17*i+129)%233 ));
   s[6] = '\0';
}
#include "test_file.c"