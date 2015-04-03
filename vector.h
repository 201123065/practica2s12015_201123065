#ifndef ____vector____
#define ____vector____


typedef struct vector vector_t;

vector_t* vector_crear(size_t tam_inicial);

bool vector_agregar(vector_t* vector, size_t indice, void * elemento);

void* vector_obtener(vector_t*, size_t indice);

size_t vector_obtener_tam(vector_t* vector);

bool vector_redim(vector_t* vector, size_t nuevotam);

void vector_destruir(vector_t* vector);

#endif
