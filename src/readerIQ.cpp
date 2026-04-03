#include "readerIQ.hpp"

IQ_data readfile(std::string filename, float Fs){
    IQ_data data;
    comfl32 sample;
    unsigned char buffer[2];

    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file.is_open()){
        warning("Не удалось открыть файл");
        return data;
    }

    // 1.
    // вычисление текущей позиции указателя и 
    // округление её вниз до ближайшего чётного числа

    // tellg() -  возвращает текущую позицию указателя чтения во входном потоке 
    std::streamsize file_size = file.tellg();

    // Проверка на чётность, отбрасывает лишний байт
    size_t n_bytes = static_cast<size_t>(file_size & ~1LL);

    // seek get(0 - смещение в байтах относительно начальной точки, std::ios::beg - точка отсчёта) 
    // (установить позицию для чтения). Команда управления курсором
    file.seekg(0, std::ios::beg);


    // Вектор данных нужного размера
    std::vector<int8_t> raw(n_bytes);

    // метод read(..) копирует указанное количество сырых байтов.
    // reinterpret_cast - это директива компилятору интерпретировать указатель 
    // на одну структуру данных как указатель на другую, без изменения самих битов
    file.read(reinterpret_cast<char*>(raw.data()), n_bytes);

    data.samples.reserve(data.NUM_samples);


}