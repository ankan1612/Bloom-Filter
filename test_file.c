int main()
{  
    long i,j; 
    bloomfilter_t * bloom;
    bloom = create_bf();
    printf("Created Filter\n");
    for( i= 0; i< 1450000; i++ )
    {  
        char s[8];
        sample_string_A(s,i);
        insert_bf( bloom, s );
    }
    for( i= 0; i< 500000; i++ )
    {      
        char s[7];
        sample_string_B(s,i);
        insert_bf( bloom, s );
    }
    for( i= 0; i< 50000; i++ )
    {  
        char s[6];
        sample_string_C(s,i);
        insert_bf( bloom, s );
    }
    printf("inserted 2,000,000 strings of length 8,7,6.\n");
   
    for( i= 0; i< 1450000; i++ )
    {  
        char s[8];
        sample_string_A(s,i);
        if( is_element( bloom, s ) != 1 )
       {  
           printf("found negative error (1)\n"); exit(0); 
       }
    }
    for( i= 0; i< 500000; i++ )
    {  
        char s[7];
        sample_string_B(s,i);
        if( is_element( bloom, s ) != 1 )
        {  
           printf("found negative error (2)\n"); exit(0); 
        }
    }
     for( i= 0; i< 50000; i++ )
    {  
        char s[6];
        sample_string_C(s,i);
        if( is_element( bloom, s ) != 1 )
       {  
           printf("found negative error (3)\n"); exit(0); 
       }
    }
    j = 0;
    for( i= 0; i< 500000; i++ )
    {  
        char s[8];
        sample_string_D(s,i);
        if( is_element( bloom, s ) != 0 )
       j+=1;
    }
    for( i= 0; i< 500000; i++ )
    {  
        char s[7];
        sample_string_E(s,i);
        if( is_element( bloom, s ) != 0 )
       j+=1;
    }
    printf("Found %ld positive errors out of 1,000,000 tests.\n",j);
    printf("Positive error rate %f%%.\n", (float)j/10000.0);
} 