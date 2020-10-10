#include <math.h>
#include <stdio.h>
#include <malloc.h>

#define TRUE    1
#define FALSE   0

typedef struct _Polynomial {
    int n;
    int c;
    struct _Polynomial *next;
} Polynomial;

int isEqual(Polynomial *a, Polynomial *b) {
    if (a->n == b->n && a->c == b->c) {
        return TRUE;
    } else {
        return FALSE;
    }
}

Polynomial * createNode(int n, int c) {
    Polynomial *this = (Polynomial *)malloc(sizeof(Polynomial));
    this->n = n;
    this->c = c;
    this->next = NULL;
    return this;
}

Polynomial * createList() {
    Polynomial *this = (Polynomial *)malloc(sizeof(Polynomial));
    this->next = NULL;
    return this;
}

void mergeList(Polynomial *this, Polynomial *that) {
    Polynomial *temp = this;
    this = this->next;
    that = that->next;
    while (this && that) {
        if (this->n == that->n) {
            this->c += that->c;
            temp = this;
            this = this->next;
            that = that->next;
        } else if (this->n < that->n) {
            temp->next = that;
            that = that->next;
            temp = temp->next;
            temp->next = this;
        } else {
            temp = this;
            this = this->next;
        }
    }
    if (that) {
        temp->next = that;
    }
    return;
}

void appendNode(Polynomial *this, Polynomial *node) {
    node->next = this->next;
    this->next = node;
    return;
}

void insertNode(Polynomial *this, Polynomial *node) {
    Polynomial *temp = this;
    this = this->next;
    while (this) {
        if (this->n == node->n) {
            this->c += node->c;
            return;
        } else if (this->n < node->n) {
            temp->next = node;
            node->next = this;
            return;
        }
        temp = this;
        this = this->next;
    }
    temp->next = node;
    return;
}

void deleteNode(Polynomial *this, Polynomial *node) {
    Polynomial *temp = this;
    this = this->next;
    while (this) {
        if (isEqual(this,node) == TRUE) {
            temp->next = this->next;
            free(this);
        } else {
            temp = this;
            this = this->next;
        }
    }
}

void printNode(Polynomial *this) {
    if (this->n == 1) {
        printf("%dx",this->c);
    } else if (this->n == 0) {
        if (this->c == 0) {
            printf("\b ");
        } else {
            printf("%d",this->c);
        }
    } else if (this->c == 1) {
        if (this->n == 1) {
            printf("x");
        } else {
            printf("x^%d",this->n);
        }
    } else {
        printf("%dx^%d", this->c, this->n);
    }
    return;
}

void printPoly(Polynomial *this) {
    this = this->next;
    printf("f(x)=");
    while (this) {
        printNode(this);
        printf("+");
        this = this->next;
    }
    printf("\b \n");
    return;
}

double getfxValue(Polynomial *this, double xn) {
    double result = 0.0;
    this = this->next;
    while (this) {
        double temp = 0.0;
        temp = pow(xn,this->n);
        temp *= this->c;
        result += temp;
        this = this->next;
    }
    return result;
}

double getdfxValue(Polynomial *this, double xn) {
    double result = 0.0;
    this = this->next;
    while (this) {
        double temp = 0.0;
        temp = pow(xn,this->n-1);
        temp *= this->c*this->n;
        result += temp;
        this = this->next;
    }
    return result;
}

double getResult(Polynomial *this, double xn) {
    double err = 1e-15;
	while (getfxValue(this,xn) > err || getfxValue(this,xn) < -1.0*err) {
		double yn = getfxValue(this,xn);
		double dyn = getdfxValue(this,xn);
		xn -= yn/dyn;
	}
	return xn;
}

int main() {
    Polynomial *fx = createList();

    Polynomial *gx = createList();

    insertNode(fx,createNode(2,2));
    insertNode(fx,createNode(3,1));
    insertNode(fx,createNode(1,3));
    insertNode(fx,createNode(9,5));
    insertNode(fx,createNode(0,0));
    insertNode(gx,createNode(9,9));
    insertNode(gx,createNode(5,7));
    insertNode(gx,createNode(0,1));
    insertNode(gx,createNode(1,1));

    printPoly(fx);
    printPoly(gx);

    mergeList(fx,gx);
    printPoly(fx);

    double result = getResult(fx,1);

    printf("%lf\n",result);

    double y = getfxValue(fx,result);
    double dy = getdfxValue(fx,result);

    printf("%lf : %lf\n",y,dy);

    // deleteNode(fx,createNode(2,2));

    // printPoly(fx);

    // deleteNode(fx,createNode(2,3));

    // printPoly(fx);
    return 0;
}