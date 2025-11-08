#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int stack[SIZE];
int top=-1;
void push(int value) {
	if(top==SIZE-1) {
		printf("stack overflow! cannot push %d\n",value);
    }else{
    	stack[++top]=value;
    	printf("%d pushed from stack.\n",value);
    }
}
void pop(){
	if(top==-1) {
		printf("stack underflow! nothing to pop.\n");
	}else{
		printf("%d popped from stack.\n",stack[top--]);
	}
}
void peek() {
	if(top==-1) {
		printf("stack is empty.\n");	
		}else{
			printf("top element is %d\n",stack[top]);
		}
}
void display() {
	if(top==-1) {
		printf("stack is empty.\n");	
	}else{
		printf("stack elements:");
		for(int i=top;i>=0;i--) {
			printf("%d",stack[i]);
		}
		printf("\n");
	}
}
int main() {
	int choice,value;
	while (1) {
		printf("\n stack operations:\n");
	    printf("1.push\n 2.pop\n 3.peek\n 4.display\n 5.exit\n");
	    printf("enter your choice:");
        scanf("%d",&choice);
        
	    switch(choice) {
	    	case 1:
	    		printf("enter value to push:");
			    scanf("%d",&value);
			    push(value);
			    break;
		    case 2:
			    pop();
		        break;
	    	case 3:
		        peek();
			    break;
	    	case 4:
	     	    display();
		    	break;
	     	case 5:
	    	    printf("Exiting...\n");
	     		return 0;
		    default:
     			printf("Invaild choice!Try again.\n");
     	}
    }
    return 0;
}
     
