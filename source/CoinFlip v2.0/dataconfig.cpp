#include "dataconfig.h"
#include <QDebug>
#include <QRandomGenerator>
#include <QTime>
#include <QtGlobal>
dataConfig::dataConfig(QObject *parent) : QObject(parent)
{

    int array1[4][4] = {{1, 1, 1, 1},
                        {1, 1, 0, 1},
                        {1, 0, 0, 0},
                        {1, 1, 0, 1} } ;

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 4;i++){
        QVector<int>v1;
        for(int j = 0 ; j < 4;j++)
        {

        v1.push_back(array1[i][j]);
        }
        v.push_back(v1);
    }

    mData.insert(1,v);


    int array2[4][4] = { {1, 0, 1, 1},
                         {0, 0, 1, 1},
                         {1, 1, 0, 0},
                         {1, 1, 0, 1}} ;

    v.clear();
    for(int i = 0 ; i < 4;i++){
        QVector<int>v1;
        for(int j = 0 ; j < 4;j++)
        {
         v1.push_back(array2[i][j]);
        }
        v.push_back(v1);
    }

    mData.insert(2,v);



    int array3[4][4] = {   {0, 0, 0, 0},
                           {0, 1, 1, 0},
                           {0, 1, 1, 0},
                           {0, 0, 0, 0}} ;
    v.clear();
    for(int i = 0 ; i < 4;i++){
        QVector<int>v1;
        for(int j = 0 ; j < 4;j++)
        {
         v1.push_back(array3[i][j]);
        }
        v.push_back(v1);
    }

    mData.insert(3,v);


    int array4[4][4] = {   {0, 1, 1, 1},
                        {1, 0, 0, 1},
                        {1, 0, 1, 1},
                        {1, 1, 1, 1}} ;
    v.clear();
    for(int i = 0 ; i < 4;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 4;j++)
      {
         v1.push_back(array4[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(4,v);


    int array5[4][4] = {  {1, 0, 0, 1},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {1, 0, 0, 1}} ;
    v.clear();
    for(int i = 0 ; i < 4;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 4;j++)
      {
         v1.push_back(array5[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(5,v);


    int array6[4][4] = {   {1, 0, 0, 1},
                        {0, 1, 1, 0},
                        {0, 1, 1, 0},
                        {1, 0, 0, 1}} ;
    v.clear();
    for(int i = 0 ; i < 4;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 4;j++)
      {
         v1.push_back(array6[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(6,v);


    int array7[4][4] = {   {0, 1, 1, 1},
                        {1, 0, 1, 1},
                        {1, 1, 0, 1},
                        {1, 1, 1, 0}} ;
    v.clear();
    for(int i = 0 ; i < 4;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 4;j++)
      {
         v1.push_back(array7[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(7,v);

    int array8[4][4] = {  {0, 1, 0, 1},
                       {1, 0, 0, 0},
                       {0, 0, 0, 1},
                       {1, 0, 1, 0}} ;
    v.clear();
    for(int i = 0 ; i < 4;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 4;j++)
      {
         v1.push_back(array8[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(8,v);

    int array9[4][4] = {   {1, 0, 1, 0},
                        {1, 0, 1, 0},
                        {0, 0, 1, 0},
                        {1, 0, 0, 1}} ;
    v.clear();
    for(int i = 0 ; i < 4;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 4;j++)
      {
         v1.push_back(array9[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(9,v);



    int array10[4][4] = {  {1, 0, 1, 1},
                        {1, 1, 0, 0},
                        {0, 0, 1, 1},
                        {1, 1, 0, 1}} ;
    v.clear();
    for(int i = 0 ; i < 4;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 4;j++)
      {
         v1.push_back(array10[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(10,v);


    int array11[4][4] = {  {0, 1, 1, 0},
                        {1, 0, 0, 1},
                        {1, 0, 0, 1},
                        {0, 1, 1, 0}} ;
    v.clear();
    for(int i = 0 ; i < 4;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 4;j++)
      {
         v1.push_back(array11[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(11,v);

    int array12[4][4] = {  {0, 1, 1, 0},
                        {0, 0, 0, 0},
                        {1, 1, 1, 1},
                        {0, 0, 0, 0}} ;
    v.clear();
    for(int i = 0 ; i < 4;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 4;j++)
      {
         v1.push_back(array12[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(12,v);


    int array13[4][4] = {    {0, 1, 1, 0},
                          {0, 0, 0, 0},
                          {0, 0, 0, 0},
                          {0, 1, 1, 0}} ;
    v.clear();
    for(int i = 0 ; i < 4;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 4;j++)
      {
         v1.push_back(array13[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(13,v);

    int array14[4][4] = {    {1, 0, 1, 1},
                          {0, 1, 0, 1},
                          {1, 0, 1, 0},
                          {1, 1, 0, 1}} ;
    v.clear();
    for(int i = 0 ; i < 4;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 4;j++)
      {
         v1.push_back(array14[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(14,v);


    int array15[4][4] = {   {0, 1, 0, 1},
                         {1, 0, 0, 0},
                         {1, 0, 0, 0},
                         {0, 1, 0, 1}} ;
    v.clear();
    for(int i = 0 ; i < 4;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 4;j++)
      {
         v1.push_back(array15[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(15,v);


    int array16[4][4] = {   {0, 1, 1, 0},
                         {1, 1, 1, 1},
                         {1, 1, 1, 1},
                         {0, 1, 1, 0}} ;
    v.clear();
    for(int i = 0 ; i < 4;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 4;j++)
      {
         v1.push_back(array16[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(16,v);

    int array17[4][4] = {  {0, 1, 1, 1},
                        {0, 1, 0, 0},
                        {0, 0, 1, 0},
                        {1, 1, 1, 0}} ;
    v.clear();
    for(int i = 0 ; i < 4;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 4;j++)
      {
         v1.push_back(array17[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(17,v);


    int array18[4][4] = { {0, 0, 0, 1},
                       {0, 0, 1, 0},
                       {0, 1, 0, 0},
                       {1, 0, 0, 0}} ;
    v.clear();
    for(int i = 0 ; i < 4;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 4;j++)
      {
         v1.push_back(array18[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(18,v);

    int array19[4][4] = {   {0, 1, 0, 0},
                         {0, 1, 1, 0},
                         {0, 0, 1, 1},
                         {0, 0, 0, 0}} ;
    v.clear();
    for(int i = 0 ; i < 4;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 4;j++)
      {
         v1.push_back(array19[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(19,v);

    int array20[4][4] = {  {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}} ;
    v.clear();
    for(int i = 0 ; i < 4;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 4;j++)
      {
         v1.push_back(array20[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(20,v);


    //21~40为困难模式6x6关卡，2为空硬币
    int array21[6][6] = {  {1, 1, 1, 1, 1, 1},
                        {1, 1, 0, 2, 1, 1},
                        {1, 0, 0, 0, 0, 1},
                        {1, 1, 0, 2, 0, 0},
                        {1, 1, 1, 1, 0, 1},
                        {1, 1, 1, 1, 1, 1}};
    v.clear();
    for(int i = 0 ; i < 6;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 6;j++)
      {
         v1.push_back(array21[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(21,v);


    int array22[6][6] =  {  {1, 1, 1, 1, 1, 1},
                         {1, 1, 0, 2, 1, 1},
                         {1, 0, 1, 1, 1, 1},
                         {1, 0, 0, 2, 0, 0},
                         {0, 0, 0, 1, 0, 1},
                         {2, 0, 1, 1, 1, 1}};
    v.clear();
    for(int i = 0 ; i < 6;i++)
    {
       QVector<int>v1;
       for(int j = 0 ; j < 6;j++)
       {
           v1.push_back(array22[i][j]);
       }
       v.push_back(v1);
    }

    mData.insert(22,v);

    int array23[6][6] = { {0, 0, 0, 0, 0, 0},
                         {0, 1, 1, 1, 1, 0},
                         {0, 1, 1, 1, 1, 0},
                         {0, 1, 1, 1, 1, 0},
                         {0, 1, 1, 1, 1, 0},
                         {0, 0, 0, 0, 0, 0} };
    v.clear();
    for(int i = 0 ; i < 6;i++)
    {
       QVector<int>v1;
       for(int j = 0 ; j < 6;j++)
       {
           v1.push_back(array23[i][j]);
       }
       v.push_back(v1);
    }

    mData.insert(23,v);


    int array24[6][6] = { {2, 0, 0, 0, 0, 2},
                         {0, 1, 1, 1, 1, 0},
                         {0, 1, 2, 1, 1, 0},
                         {0, 1, 2, 2, 1, 0},
                         {0, 1, 1, 1, 1, 0},
                         {2, 0, 0, 0, 0, 2} };
    v.clear();
    for(int i = 0 ; i < 6;i++)
    {
       QVector<int>v1;
       for(int j = 0 ; j < 6;j++)
       {
           v1.push_back(array24[i][j]);
       }
       v.push_back(v1);
    }

    mData.insert(24,v);

    int array25[6][6] = { {1, 1, 0, 0, 1, 1},
                         {0, 1, 0, 1, 1, 1},
                         {1, 1, 0, 0, 1, 0},
                         {1, 1, 0, 1, 1, 0},
                         {1, 1, 1, 1, 1, 1},
                         {1, 1, 0, 0, 1, 1} };
    v.clear();
    for(int i = 0 ; i < 6;i++)
    {
       QVector<int>v1;
       for(int j = 0 ; j < 6;j++)
       {
           v1.push_back(array25[i][j]);
       }
       v.push_back(v1);
    }

    mData.insert(25,v);

    int array26[6][6] = { {2, 2, 2, 2, 2, 2},
                        {2, 0, 2, 0, 0, 0},
                        {2, 0, 0, 0, 0, 2},
                        {0, 0, 2, 0, 0, 0},
                        {2, 0, 0, 0, 1, 2},
                        {2, 2, 2, 2, 2, 2} };
    v.clear();
    for(int i = 0 ; i < 6;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 6;j++)
      {
          v1.push_back(array26[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(26,v);

    int array27[6][6] = {  {1, 1, 0, 0, 0, 0},
                         {1, 1, 0, 0, 0, 1},
                         {1, 1, 0, 0, 0, 0},
                         {1, 1, 0, 0, 0, 0},
                         {1, 1, 0, 0, 0, 1},
                         {1, 1, 0, 0, 0, 0} };
    v.clear();
    for(int i = 0 ; i < 6;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 6;j++)
      {
          v1.push_back(array27[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(27,v);


    int array28[6][6] = {  {0, 0, 0, 0, 0, 1},
                         {0, 0, 1, 0, 0, 0},
                         {0, 1, 1, 0, 0, 0},
                         {1, 0, 0, 1, 1, 0},
                         {1, 1, 0, 1, 0, 0},
                         {1, 1, 1, 0, 0, 0} };
    v.clear();
    for(int i = 0 ; i < 6;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 6;j++)
      {
          v1.push_back(array28[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(28,v);

    int array29[6][6] = {  {0, 0, 0, 0, 0, 0},
                         {1, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0} };
    v.clear();
    for(int i = 0 ; i < 6;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 6;j++)
      {
          v1.push_back(array29[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(29,v);

    int array30[6][6] = {  {2, 1, 0, 0, 0, 0},
                         {1, 1, 0, 0, 0, 1},
                         {1, 1, 0, 1, 0, 0},
                         {1, 1, 1, 1, 1, 0},
                         {1, 1, 0, 1, 0, 1},
                         {1, 1, 0, 0, 0, 0} };
    v.clear();
    for(int i = 0 ; i < 6;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 6;j++)
      {
          v1.push_back(array30[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(30,v);


    int array31[6][6] = {  {0, 0, 0, 0, 0, 1},
                         {0, 0, 1, 2, 2, 0},
                         {0, 1, 1, 2, 2, 0},
                         {1, 1, 2, 1, 1, 0},
                         {1, 1, 2, 1, 0, 0},
                         {1, 0, 1, 0, 0, 0} };
    v.clear();
    for(int i = 0 ; i < 6;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 6;j++)
      {
          v1.push_back(array31[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(31,v);

    int array32[6][6] = {  {0, 0, 0, 0, 0, 0},
                         {1, 2, 0, 0, 0, 0},
                         {0, 0, 2, 0, 0, 0},
                         {0, 0, 0, 2, 1, 0},
                         {0, 0, 0, 0, 2, 0},
                         {0, 0, 0, 1, 0, 0} };
    v.clear();
    for(int i = 0 ; i < 6;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 6;j++)
      {
          v1.push_back(array32[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(32,v);



    int array33[6][6] = {  {2, 0, 0, 0, 0, 1},
                         {0, 2, 1, 0, 1, 0},
                         {0, 1, 1, 1, 2, 0},
                         {1, 1, 2, 1, 1, 0},
                         {1, 1, 0, 2, 1, 0},
                         {1, 1, 1, 0, 0, 2} };
    v.clear();
    for(int i = 0 ; i < 6;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 6;j++)
      {
          v1.push_back(array33[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(33,v);

    int array34[6][6] = {  {0, 0, 0, 0, 0, 0},
                         {0, 1, 0, 0, 1, 0},
                         {0, 0, 0, 1, 0, 0},
                         {0, 0, 1, 1, 0, 0},
                         {0, 1, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1} };
    v.clear();
    for(int i = 0 ; i < 6;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 6;j++)
      {
          v1.push_back(array34[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(34,v);


    int array35[6][6] = {  {0, 0, 0, 0, 0, 0},
                         {0, 2, 0, 1, 2, 0},
                         {0, 0, 0, 2, 0, 0},
                         {0, 0, 2, 2, 0, 0},
                         {0, 2, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 2} };
    v.clear();
    for(int i = 0 ; i < 6;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 6;j++)
      {
          v1.push_back(array35[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(35,v);

    int array36[6][6] = {  {1, 1, 1, 0, 1, 0},
                         {1, 0, 1, 0, 1, 0},
                         {1, 0, 1, 0, 1, 0},
                         {1, 0, 1, 0, 1, 0},
                         {1, 0, 1, 0, 1, 0},
                         {1, 1, 1, 0, 1, 0} };
    v.clear();
    for(int i = 0 ; i < 6;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 6;j++)
      {
          v1.push_back(array36[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(36,v);


    int array37[6][6] = {  {1, 2, 1, 0, 1, 0},
                         {1, 0, 1, 0, 1, 0},
                         {1, 0, 1, 0, 1, 0},
                         {1, 0, 1, 0, 1, 0},
                         {1, 0, 1, 0, 1, 0},
                         {1, 2, 1, 0, 1, 0} };
    v.clear();
    for(int i = 0 ; i < 6;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 6;j++)
      {
          v1.push_back(array37[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(37,v);

    int array38[6][6] = {  {0, 0, 0, 0, 1, 0},
                         {0, 2, 0, 0, 2, 0},
                         {0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0},
                         {0, 2, 0, 0, 2, 0} };
    v.clear();
    for(int i = 0 ; i < 6;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 6;j++)
      {
          v1.push_back(array38[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(38,v);


    int array39[6][6] = {  {0, 0, 0, 0, 0, 0},
                         {0, 0, 1, 0, 0, 0},
                         {0, 0, 0, 1, 0, 0},
                         {0, 0, 0, 1, 0, 0},
                         {0, 0, 1, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0} };
    v.clear();
    for(int i = 0 ; i < 6;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 6;j++)
      {
          v1.push_back(array39[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(39,v);

    int array40[6][6] = {  {0, 0, 0, 0, 0, 0},
                         {0, 2, 0, 0, 1, 0},
                         {0, 0, 1, 0, 1, 0},
                         {0, 0, 1, 0, 1, 0},
                         {0, 2, 0, 0, 1, 0},
                         {0, 0, 0, 0, 0, 0} };
    v.clear();
    for(int i = 0 ; i < 6;i++)
    {
      QVector<int>v1;
      for(int j = 0 ; j < 6;j++)
      {
          v1.push_back(array40[i][j]);
      }
      v.push_back(v1);
    }

    mData.insert(40,v);



    //随机关
    QRandomGenerator rng(QTime::currentTime().msecsSinceStartOfDay());
    v.clear();

    unsigned int arr[36];
    rng.fillRange(arr,10);
    int num2=0;
    int sum2=0;
    for(int i = 0 ; i < 6;i++)
    {
       QVector<int>v1;
       for(int j = 0 ; j < 6;j++)
       {
           num2=arr[i*6 + j]%2;
           v1.push_back(num2);
           if(num2==1){
               sum2++;
           }
       }
       v.push_back(v1);
    }

    //还需要设置成偶数个，奇数个不行，可以利用vector的性质来做
    int changedValue2=v[4][4];//改变中间那个

    if((sum2&1)!=0){
       //如果为奇数，则改变中间一个
       if(changedValue2==0){
           v[4][4]=1;
       }
       else{
           v[4][4]=0;
       }
    }
    mData.insert(41,v);

}
