#define _CRT_SECURE_NO_WARNINGS
#include "CommentConvert.h"
void CommentConvert(FILE * pfIn, FILE *pfOut)
{
	enum STATE state = NUL_STSTE;
	while (state != END_STATE)
	{
		switch(state)
		{
		case NUL_STSTE:
			{
				DoNulState(pfIn, pfOut, &state);
				break;
			}
			
		case C_STATE:
			{
				DoCState(pfIn, pfOut, &state);
				break;
			}
		case CPP_STATE:
			{
				DoCppState(pfIn, pfOut, &state);
				break;
			}
		default:
			break;
		}
	}

}
void DoNulState(FILE * pfIn, FILE *pfOut, enum STATE* ptr)//无状态转换
{
	char first = fgetc(pfIn);
	char second = 0;
	assert(pfOut && pfIn && ptr);
	switch (first)
	{
	 case '/':
		
			second = fgetc(pfIn);
			switch(second)
			{
			case '*':
				
					fputc('/',pfOut);
					fputc('/', pfOut);
					*ptr = C_STATE;
					break;
				
			case '/':
				
					fputc('/', pfOut);

					fputc('/', pfOut);
					*ptr = CPP_STATE;

					break;
				
			default:
				
					
					ungetc(second,pfOut);
					*ptr = NUL_STSTE;
					break;
				
			}
			break;
		
		
	case EOF:
		
			
			*ptr = END_STATE;
			break;
		
	default:
		
			fputc(first,pfOut);
			*ptr = NUL_STSTE;
			break;
		
	}
	
}

void DoCState(FILE * pfIn, FILE *pfOut, enum STATE* ptr)
{
	char first = fgetc(pfIn);
	char second = 0;
	char third = 0;
	assert(pfOut && pfIn && ptr);
	switch (first)
	{
	case '*':
		second = fgetc(pfIn);
		switch(second)
		{
		case '/':
			third = fgetc(pfIn);
			*ptr = NUL_STSTE;
			if ((third == '\n') && (third != EOF))
			{
				ungetc('\n',pfIn);
			
			}
		
			fputc('\n', pfOut);
			*ptr = NUL_STSTE;
		
			break;
		
	default:
		
		ungetc(second, pfIn);
		fputc(first, pfOut);
		*ptr = C_STATE;
		break;
		
			}
	break;

	case '\n':
		
		fputc('\n', pfOut);
		fputc('/', pfOut);
		fputc('/', pfOut);
		*ptr = C_STATE;
		break;
		
	
	default:
		
		fputc(first, pfOut);
		*ptr = C_STATE;
		break;
		
		
}
}
void DoCppState(FILE * pfIn, FILE *pfOut, enum STATE* ptr)
{
	char first = 0;
	char second = 0;
	first = fgetc(pfIn);
	enum STATE state = NUL_STSTE;
	switch(first)
	{
	case '\n':

	
				 fputc(first, pfOut);
				 *ptr = NUL_STSTE;
				 break;
	
	case EOF:
	

				*ptr = END_STATE;
				break;
	
	default:
	
			   fputc(first, pfOut);
			   *ptr = CPP_STATE;
			   break;

	
	}
	
		
	
}
