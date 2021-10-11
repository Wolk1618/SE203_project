#include <stddef.h>
#include <stdint.h>

void *memset(void *s, int c, size_t n);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);

void *memset(void *s, int c, size_t n) {
	uint8_t *src = s;
	for(uint8_t *p = src; p < src+n; p++) {
		*p = c;
	}
}

void *memcpy(void *dest, const void *src, size_t n) {
	uint8_t *sd = dest;
	const uint8_t *ss = src;
	for(int i = 0; i < n; i ++) {
		*(sd + i) = *(ss + i);
	}
}

void  *memmove(void *dest, const void *src, size_t n) {
	uint8_t *sd = dest;
	const uint8_t *ss = src;
	if(*sd <= *ss + n) {
		for(int i = 0; i < n; i++) {
			*(sd + n - i) = *(ss + n - i);
		}
	} else {
		for(int i = 0; i < n; i++) {
                        *(sd + i) = *(ss + i);
                }
	}
}

int memcmp(const void *s1, const void *s2, size_t n) {
	const uint8_t *ss1 = s1;
	const uint8_t *ss2 = s2;
	int i = 0;
	while(i <= n && *(ss1 + i) == *(ss2 + i)) {
		i ++;
	}
	if(i == n) {
		return 0;
	} else {
		return *(ss1 + i) - *(ss2 + i);
	}
}

