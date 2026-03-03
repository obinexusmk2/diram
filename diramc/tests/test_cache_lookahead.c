#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "diram/core/diram.h"

static size_t g_last_alloc_size = 0;

void* diram_alloc(diram_context_t* ctx, size_t size, phenotype_t intent) {
    (void)ctx;
    (void)intent;
    g_last_alloc_size = size;
    return malloc(size);
}

void diram_free(diram_context_t* ctx, void* memory) {
    (void)ctx;
    free(memory);
}

dag_node_t* diram_navigate_dag(diram_context_t* ctx, phenotype_t target) {
    (void)ctx;
    (void)target;
    return NULL;
}

#include "../src/core/feature-alloc/cache_lookahead.c"

int main(void) {
    phenotype_t predicted = {0};

    int rc = prefetch_by_phenomenon(NULL, predicted);
    assert(rc == 0);
    assert(g_last_alloc_size == 1024U);

    printf("cache_lookahead unit test passed\n");
    return 0;
}
