class SomeClass { };

void foo(int i) { }
void foo(float s) { }
void foo(SomeClass) { }

// int foo(int i);      // ambiguous, will not compile

int main() {
    int i;
    float j;
    SomeClass c;

    foo(i);
    foo(j);
    foo(c);
}

int main() { }
