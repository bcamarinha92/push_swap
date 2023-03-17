#include <stdlib.h>
#include <stdio.h>

typedef struct s_node {
    int data;
    struct s_node* next;
} t_node;

t_node* ft_add_to_list(t_node* list, int val) 
{
    t_node* new_node;
    t_node* current_node;

    new_node = (t_node*)malloc(sizeof(t_node));
    new_node->data = val;
    new_node->next = NULL;

    if (list == NULL) 
    {
        list = new_node;
    } else 
    {
        current_node = list;
        while (current_node->next != NULL) 
            current_node = current_node->next;
        current_node->next = new_node;
    }
    return list;
}

t_node* ft_swap_node(t_node* list) 
{
    int temp ;

    if (list == NULL || list->next == NULL) 
        return list; 
    temp = list->data;
    list->data = list->next->data;
    list->next->data = temp;
    return list;
}

t_node* ft_rotate_node(t_node* list) 
{
    t_node* current_node;

    if (list == NULL || list->next == NULL) 
        return list;
    current_node = list;
    while (current_node->next != NULL) 
        current_node = current_node->next;
    current_node->next = list;
    list = list->next;
    current_node->next->next = NULL;
    return list;
}

t_node* ft_rever_rotate(t_node* list) 
{
    t_node* current_node = list;
    t_node* previous_node = NULL;

    if (list == NULL || list->next == NULL)
        return list;
    current_node = list;
    previous_node = NULL;
    while (current_node->next != NULL) 
    {
        previous_node = current_node;
        current_node = current_node->next;
    }
    current_node->next = list;
    list = current_node;
    previous_node->next = NULL;
    return list;
}

t_node* move_node(t_node* stack_src, t_node* stack_dst) 
{
    t_node* element;
    
    if (stack_src == NULL) 
        return stack_dst;
    element = stack_src;
    stack_src = stack_src->next;
    element->next = stack_dst;
    stack_dst = element;
    return stack_dst;
}

int ft_find_max(t_node* head) 
{
    int max;
    t_node* current;

    max = head->data;
    current = head->next;
    while (current != NULL) {
        if (current->data > max)
            max = current->data;
        current = current->next;
    }
    return max;
}

int ft_find_min(t_node* head) 
{
    int min;
    t_node* current;

    min = head->data;
    current = head->next;
    while (current != NULL) {
        if (current->data < min)
            min = current->data;
        current = current->next;
    }
    return min;
}

int ft_is_sorted(t_node* head) 
{
    t_node* current;

    current = head;
    while (current != NULL && current->next != NULL) 
    {
        if (current->data > current->next->data)
            return 0;
        current = current->next;
    }
    return 1;
}

void	ft_small_sort(t_node *stack)
{
	int	maximum;
	int	minimum;

	maximum = ft_find_max(stack);
	minimum = ft_find_min(stack);
	while (!ft_is_sorted(stack))
	{
		if (stack->data != minimum && stack->next->data == maximum)
        {
			ft_rever_rotate(stack);
            printf("rra\n");
        }
		else if (stack->data == maximum && stack->next->data == minimum)
        {
			ft_rotate_node(stack);
            printf("ra\n");
        }
		else
        {
			ft_swap_node(stack);
            printf("sa\n");
        }
	}
}

int main(int argc, char *argv[]) {
    t_node* list = NULL;

    for (int i = 1; i < argc; i++) {
        int val = atoi(argv[i]);
        list = ft_add_to_list(list, val);
    }

    //list = ft_swap_node(list);
    //list = ft_rever_rotate(list);
    ft_small_sort(list);
    // Print the linked list
    // t_node* current_node = list;
    // while (current_node != NULL) {
    //     printf("%d ", current_node->data);
    //     current_node = current_node->next;
    // }

    return 0;
}