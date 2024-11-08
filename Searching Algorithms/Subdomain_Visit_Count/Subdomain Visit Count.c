#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char domain[100];
    int count;
} DomainCount;

int compare(const void *a, const void *b) {
    return ((DomainCount *)b)->count - ((DomainCount *)a)->count;
}

void addVisitCount(char *domain, int count, DomainCount *domainCounts, int *size) {
    char *subdomain = strtok(domain, ".");
    char fullDomain[100] = "";
    
    // Build subdomains and add counts
while (subdomain != NULL) {
        if (strlen(fullDomain) > 0) {
            strcat(fullDomain, ".");
        }
        strcat(fullDomain, subdomain);
        
        // Check if the fullDomain already exists
        int found = 0;
        for (int i = 0; i < *size; i++) {
            if (strcmp(domainCounts[i].domain, fullDomain) == 0) {
                domainCounts[i].count += count;
                found = 1;
                break;
            }
        }
        
        // If not found, add a new entry
        if (!found) {
            strcpy(domainCounts[*size].domain, fullDomain);
            domainCounts[*size].count = count;
            (*size)++;
        }
        
        subdomain = strtok(NULL, ".");
    }
}

void subdomainVisits(char **cpdomains, int cpdomainsSize) {
    DomainCount domainCounts[1000];
    int size = 0;

    for (int i = 0; i < cpdomainsSize; i++) {
        char *space = strchr(cpdomains[i], ' ');
        *space = '\0'; // Split count and do
          int count = atoi(cpdomains[i]);
        char *domain = space + 1;

        addVisitCount(domain, count, domainCounts, &size);
        *space = ' '; // Restore the original string
    }

    // Sort by count
    qsort(domainCounts, size, sizeof(DomainCount), compare);

    // Print results
    for (int i = 0; i < size; i++) {
        printf("%d %s\n", domainCounts[i].count, domainCounts[i].domain);
    }
}

int main() {
    char *cpdomains[] = {
        "9001 discuss.leetcode.com",
        "50 yahoo.com",
        "1 intel.mail.com",
        "5 wiki.org"
    };
    int cpdomainsSize = sizeof(cpdomains) / sizeof(cpdomains[0]);
    
    subdomainVisits(cpdomains, cpdomainsSize);
    return 0;
}
