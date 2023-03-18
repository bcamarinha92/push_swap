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

t_node* ft_swap_node(t_node** list) 
{
    int temp ;

    if ((*list) == NULL || (*list)->next == NULL) 
        return (*list); 
    temp = (*list)->data;
    (*list)->data = (*list)->next->data;
    (*list)->next->data = temp;
    return (*list);
}

void ft_rotate_node(t_node **stack)
{
    t_node *tmp;
    t_node *first;
    
    if (*stack == NULL || (*stack)->next == NULL)
        return;
    tmp = *stack;
    first = *stack;
    while (tmp->next)
        tmp = tmp->next;
    *stack = (*stack)->next;
    first->next = NULL;
    tmp->next = first;
}

void ft_rever_rotate(t_node **list)
{
    t_node *current_node = *list;
    t_node *previous_node = NULL;

    if (*list == NULL || (*list)->next == NULL)
        return;
    current_node = *list;
    previous_node = NULL;
    while (current_node->next != NULL)
    {
        previous_node = current_node;
        current_node = current_node->next;
    }
    current_node->next = *list;
    *list = current_node;
    previous_node->next = NULL;
}

void ft_move_node(t_node **stack_src, t_node **stack_dst) 
{
    if (*stack_src == NULL) 
        return;
    t_node *element = *stack_src;
    *stack_src = (*stack_src)->next;
    element->next = *stack_dst;
    *stack_dst = element;
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

void	ft_three_sort(t_node **stack)
{
	int	maximum;
	int	minimum;

	maximum = ft_find_max(*stack);
	minimum = ft_find_min(*stack);
	while (!ft_is_sorted(*stack))
	{
		if ((*stack)->data != minimum && (*stack)->next->data == maximum)
        {
			ft_rever_rotate(stack);
            printf("rra\n");
        }
		else if ((*stack)->data == maximum && (*stack)->next->data == minimum)
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

int ft_print_list(t_node *stack) 
{
    t_node *current;
    current = stack;
    while (current != NULL) 
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    return(0);
}

int ft_stack_length(t_node *stack) 
{
    int i;

    i = 0;
    while (stack != NULL) 
    {
        i++;
        stack = stack->next;
    }
    return i;
}

void	ft_five_sort(t_node **stack, t_node **stack2)
{
	while (ft_stack_length(*stack) > 3)
	{
		if ((*stack)->data == ft_find_min(*stack))
        {
			ft_move_node(stack, stack2);
            printf("pb\n");
        }
		else
        {
            if ((*stack)->next->data == ft_find_min(*stack))
            {
			    ft_rotate_node(stack);
                printf("ra\n");
            }
            else
            {
                ft_rever_rotate(stack);
                printf("rra\n");
            }
        }
	}
    ft_three_sort(stack);
    while (ft_stack_length(*stack2))
    {
        ft_move_node(stack2, stack);
        printf("pa\n");
    }
}

int main(int argc, char **argv) 
{
    t_node *list;
    t_node *list2;

    int i;
    int val; 
    i = 1;
    if (argc > 1)
    {
        list = NULL;
        list2 = NULL;

        while (i < argc)
        {
            val = atoi(argv[i]);
            list = ft_add_to_list(list, val);
            i++;
        }
        if (!ft_is_sorted(list))
        {
            if (argc - 1 < 4)
                ft_three_sort(&list);
            else if (argc -1 < 6)
                ft_five_sort(&list,&list2);
        }
    }
    return 0;
}