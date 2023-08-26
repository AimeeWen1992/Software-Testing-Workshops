#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
/**
* Determine if the string s starts with the string prefix.
* @param s - the string to see if it starts with prefix
* @param prefix - the prefix to test
* @returns true if the strings begins with the prefix.
*/
int startsWith(const char s[], const char prefix[])
{
	/*char buf[20];
	int i;
	int sz = strlen(prefix);
	for (i = 0; i < sz; i++)
	{
		buf[i] = s[i];
	}
	buf[sz] = '\0';
	return 0 == strcmp(buf, prefix);*/

	int i, validation = 1;
	int sz;
	if (s[0] == '\0' && prefix[0] == '\0')
	{
		validation = 1;
	}
	else if (s[0] != '\0' && prefix[0] == '\0')
	{
		validation = 0;
	}
	else
	{
		sz = strlen(prefix);
		for (i = 0; i < sz && validation; i++)
		{
			if (s[i] != prefix[i])
			{
				validation = 0;
			}
		}
	}

	return validation;
}
/**
* Determine if the string s ends with the string suffix.
* @param s - the string to see if it ends with suffix
* @param suffix - the suffix to test
* @returns true if the strings ends with the suffix.
*/
int endsWith(const char s[], const char suffix[])
{
	/*int sz = strlen(suffix);
	int slen = strlen(s);
	return 0 == strcmp(s + slen - sz, suffix);*/

	int sz, slen;
	int validation = 1;

	if (s[0] == '\0' && suffix[0] == '\0')
	{
		validation = 1;
	}
	else if (s[0] != '\0' && suffix[0] == '\0')
	{
		validation = 0;
	}
	else if (s[0] == '\0' && suffix[0] != '\0')
	{
		validation = 0;
	}
	else
	{
		sz = strlen(suffix);
		slen = strlen(s);
		validation = !strcmp(s + slen - sz, suffix);
	}

	return validation;

}

int main(void)
{
	char s1[] = { "upended" };
	char prefix[] = { "up" };
	char suffix[] = { "ed"};
	printf("%s does %s start with %s\n",
		s1, startsWith(s1, prefix) ? "" : " not", prefix);
	printf("%s does %s end with %s\n",
		s1, endsWith(s1, suffix) ? "" : " not", suffix);
	return 0;
}