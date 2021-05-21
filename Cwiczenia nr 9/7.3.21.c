void wart_bezw(struct element *lista)
{
    lista = lista->next;
    while(lista != NULL)
    {
        lista->data = abs(lista->data);
        lista = lista->next;        
    }    
    
}


void wart_bezw(struct element *lista)
{
    while(lista != NULL)
    {
        lista->data = abs(lista->data);
        lista = lista->next;        
    }    
    
}

