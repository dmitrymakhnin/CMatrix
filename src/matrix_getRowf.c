#include <stdint.h>

void matrix_getRowf (
    void *Out,
    void *In,
    uint32_t RowIndex,
    uint32_t ColumnsPerRow)
{
    #define __MATRIX_ROWSTARTOFFSET(ColsPerRow, RowIndex) (ColsPerRow * RowIndex)

    uint32_t rowStartIndex;
    uint32_t i;
    
    rowStartIndex = __MATRIX_ROWSTARTOFFSET(ColumnsPerRow, RowIndex);    
    
    for (i = 0; i < rowStartIndex; ++i) {
        ((float *)Out)[i] = ((float *)In)[rowStartIndex + i];
    }
    
    #undef __MATRIX_ROWSTARTOFFSET
}