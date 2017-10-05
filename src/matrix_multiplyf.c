void matrix_multiplyf (
    void *Out, 
    void *A, 
    void *B, 
    int r1, 
    int c1r2, 
    int c2)
{    
    #define __MATRIX_INDEX(__RowLength, __RowIndex, __ColumnIndex) (__RowLength * __RowIndex + __ColumnIndex)

    int i;
    int j;    
    int k;    
    
    for (i = 0; i < r1; ++i) {
        for (j = 0; j < c2; ++j) {
            float tmp; 
            
            tmp = 0;
            
            for (k = 0; k < c1r2; ++k) {       
                float tmp1 = ((float *)A)[__MATRIX_INDEX(c1r2, i, k)];
                float tmp2 = ((float *)B)[__MATRIX_INDEX(c2, k, j)];
          
                tmp = tmp
                    + tmp1
                    * tmp2
                    ;
            }
            
            ((float *)Out)[__MATRIX_INDEX(c2 ,i, j)] = tmp;
        }
    }
    
    #undef __MATRIX_INDEX
}