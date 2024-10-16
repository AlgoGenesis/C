int hash3(const char *str) {
    int hash = 0;
    while (*str) {
        hash = (hash * 17 + *str++) % BLOOM_SIZE;
    }
    return hash;
}

// Add a string to the Bloom filter
void add_to_bloom(const char *str) {
    int hash1_value = hash1(str);
    int hash2_value = hash2(str);
    int hash3_value = hash3(str);

    bloom_filter[hash1_value] = 1;
    bloom_filter[hash2_value] = 1;
    bloom_filter[hash3_value] = 1;
}

// Check if a string is possibly in the Bloom filter
int is_in_bloom(const char *str) {
    int hash1_value = hash1(str);
    int hash2_value = hash2(str);
    int hash3_value = hash3(str);

    return bloom_filter[hash1_value] && bloom_filter[hash2_value] && bloom_filter[hash3_value];
}

