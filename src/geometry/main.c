#include <libgeometry/parser.h>

int main()
{
    char* message
            = "Введите фигуру в нужном формате\n"
              "Пример: circle(0 0, 1.5)\n\n"
              "Для того, чтобы выйти введите q.\n";
    puts(message);
    parse_start();
    return 0;
}