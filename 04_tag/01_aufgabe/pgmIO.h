#pragma once
#include <cstdio>

inline bool readPGM(const char* filename, unsigned char** pData, unsigned int * sx, unsigned int * sy)
{	
	FILE* fp = fopen(filename, "rb");
	
	if(!fp) return false;
	char formatSpecifier[16];

	if (fscanf(fp, "%s\n", formatSpecifier) != 1)
		return false;

	if (fscanf(fp, "%u %u\n", sx, sy) != 2)
		return false;

	int nGrayValues = 0;
	if (fscanf(fp, "%d\n", &nGrayValues) != 1)
		return false;

	delete[] * pData;
	*pData = new unsigned char[*sx * *sy];
	fread(*pData, *sx * sizeof(unsigned char), *sy, fp);

	fclose(fp);
	return true;
}


inline bool writePGM(const char* filename, const unsigned char* pData, unsigned int sx, unsigned int sy)
{

	FILE* fp = fopen(filename, "wb");

	if (!fp) return false;

	fprintf(fp, "P5\n%u %u\n255\n", sx, sy);

	if (1 != fwrite(pData, sx*sy, 1, fp))
	{
		fclose(fp);
		return false;
	}

	fclose(fp);
	return true;
}