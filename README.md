# Bloom Filter

Implement a Bloom ﬁlter for 2,000,000 strings with an error rate of less than 3%, using only 2Mbyte of memory. To achieve this, you create eight bit arrays, ***each of 2,000,000 bits (that is, 250,000 char)***. For each of these, you select a random hash function ***hi*** from a universal family. To insert a ***string s***, you set the ***hi(S)-th bit*** to one in the i-th bit array, ***for i = 0,...,7.*** To query whether a string q is contained in the set, you check whether ***hi(q)*** is one in the ***i-th bit*** array, for all ***i***.

***The structure must support the following operations :***
- Creates a Bloom ﬁlter with the above speciﬁcation :
```sh
bf_t *create_bf()
```
- Inserts the string *s into the Bloom ﬁlter *b :
```sh
void insert_bf(bf_t *b, char *s)
```
- returns 1 if the string *q is accepted by the Bloom ﬁlter, and 0 else :
```sh
int is_element(bf_t *b, char *q)
