
set(SOURCE_FILES
        ashop.h
        business_logic/BuyerUseCases.cpp
        business_logic/BuyerUseCases.h
        infrastructure/BasketBase.h
        infrastructure/BasketRepositoryBase.h
        infrastructure/ItemBase.h
        infrastructure/ItemRepositoryBase.h
        infrastructure/impl/memory/BasketRepositoryMemory.cpp
        infrastructure/impl/memory/BasketRepositoryMemory.h
        presentation/Api.cpp
        presentation/Api.h
        presentation/JsonSerializer.cpp
        presentation/JsonSerializer.h)

add_library(ashop_cplusplus STATIC ${SOURCE_FILES})

target_link_libraries(ashop_cplusplus ${CONAN_LIBS})
target_compile_options(ashop_cplusplus PRIVATE -fvisibility=hidden)
