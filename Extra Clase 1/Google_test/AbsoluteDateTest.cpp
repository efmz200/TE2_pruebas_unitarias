#include "gtest/gtest.h"

#include "../Grafo.h"


#include <iostream>

TEST(AbsoluteDateTestSuite, ExampleDate){
    Grafo *graf=new Grafo();
    cout<<"hola";
    graf->agregaVert("a");
    graf->agregaVert("b");
    graf->agregaVert("bsdfvf");
    graf->agregaVert("bsdcvsd");
    graf->agregaVert("bsdv");
    graf->agregaVert("nvgh");
    graf->agregaVert("ghvk");

    EXPECT_EQ(graf->lengrafo(),7);
}

TEST(AbsoluteDateTestSuite, IncorrectDate){ // 12/0/2020 -> 0
    GregorianDate gregDate;
    gregDate.SetMonth(12);
    gregDate.SetDay(0);
    gregDate.SetYear(2020);

    ASSERT_EQ(gregDate.getAbsoluteDate(),0);
}
