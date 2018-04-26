#ifndef __COMMENT_CONVERT_H__
#define __COMMENT_CONVERT_H__
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
enum STATE
{
	END_STATE,
	NUL_STSTE,
	C_STATE,
	CPP_STATE
	
};
void DoNulState(FILE * pfIn, FILE *pfOut, enum STATE* ptr);
void DoCState(FILE * pfIn, FILE *pfOut, enum STATE* ptr);
void DoCppState(FILE * pfIn, FILE *pfOut, enum STATE* ptr);
void CommentConvert(FILE * pfIn, FILE *pfOut);

#endif
