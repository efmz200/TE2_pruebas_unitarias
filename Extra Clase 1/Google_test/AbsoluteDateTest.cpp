#include "gtest/gtest.h"

#include "../Grafo.h"
#include "/home/drump1/Desktop/te 2/TE2_pruebas_unitarias/servidor/Vertice.h"

#include <iostream>

TEST(AbsoluteDateTestSuite, lenProof){
    Grafo *graf=new Grafo();
    graf->agregaVert("a");
    graf->agregaVert("b");
    graf->agregaVert("bsdfvf");
    graf->agregaVert("bsdcvsd");
    graf->agregaVert("bsdv");
    graf->agregaVert("nvgh");
    graf->agregaVert("ghvk");

    EXPECT_EQ(graf->lengrafo(),7);
}

TEST(AbsoluteDateTestSuite, NullProof){
    Grafo *graf=new Grafo();
    graf->agregaVert("a");
    graf->agregaVert("b");
    ASSERT_EQ(graf->getVertice("c"), nullptr);
}

TEST(AbsoluteDateTestSuite, lenProof2){
    Grafo *graf=new Grafo();
    ASSERT_EQ(graf->lengrafo(),0 );
}

