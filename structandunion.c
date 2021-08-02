#include <stdio.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    float height;
} Person;

typedef union {
    float salary;
} Job;

int main() {

    Person p;
    p.name = "Kiki Abdullah";
    p.age = 23;
    p.height = (float) 67.71;
    
    Job j;
    j.salary = 2500;

    printf("Name: %s\nAge: %d\nHeight: %.2f inch\nSalary: %.2f USD", p.name, p.age, p.height, j.salary);
    return 0;
}