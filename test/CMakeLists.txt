include_directories(.)

add_executable(BuyerUseCasesTest ashop/business_logic/BuyerUseCasesTest.cpp)
target_link_libraries(BuyerUseCasesTest ashop_cplusplus ${CONAN_LIBS})
add_test(BuyerUseCasesTest BuyerUseCasesTest)

add_executable(BasketRepositoryMemoryTest ashop/infrastructure/impl/memory/BasketRepositoryMemoryTest.cpp)
target_link_libraries(BasketRepositoryMemoryTest ashop_cplusplus ${CONAN_LIBS})
add_test(BasketRepositoryMemoryTest BasketRepositoryMemoryTest)
