#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//f_dst_s = 8
//src = AAAB
//dst = CCC
//
//dst = CCCAAAB\0

//f_dst_s = 4
//src = AAAB
//dst = CCC\0
//
//dst = CCC\0

size_t	ft_strlcat(char *dst, const char *src, size_t f_dst_s)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = strlen(dst);
	src_len = strlen(src);
	if (f_dst_s == 0)
		return (src_len);
	if (dst_len < f_dst_s)
	{
		while (src[i] && i + 1 < f_dst_s - dst_len)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
		return (src_len + dst_len);
	}
	return (src_len + f_dst_s);
}

int	main(void)
{
	char	*dst = malloc(30);
	char	*src = malloc(30);
	char	*dst2 = malloc(30);
	char	*src2 = malloc(30);
	size_t	oreturn = 0;
	size_t	mreturn = 0;

	strcpy(dst, "CCC");
	strcpy(src, "AAAB");
	strcpy(dst2, "CCC");
	strcpy(src2, "AAAB");

	oreturn = strlcat(dst, src, 4);
	mreturn = ft_strlcat(dst2, src2, 4);

	printf("o:\t%s\n", dst);
	printf("m:\t%s\n", dst2);
	puts("");
	printf("or:\t%zu\n", oreturn);
	printf("mr:\t%zu\n", mreturn);

	free(dst);
	free(src);
	free(dst2);
	free(src2);
}
