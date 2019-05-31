/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ec.edu.espe.exercise.controller;

/**
 *
 * @author Andres Garcia
 */
public class Operations {

    public static int Multiply(int factor1, int factor2){
    
        int result=0;
        int factor1Aux=factor1;
        int factor2Aux=factor2;
        
        if(factor1<0){
            factor1Aux*=-1 ;
        }
        if(factor2<0){
            factor2Aux*=-1;
        }
      
        for(int i=0; i<factor2Aux ; i++){
            result +=factor1Aux;
        
        }
        if(factor1<0)
            result*=-1;
        if(factor2<0)
            result*=-1;
        
        
         return result;
    }
       

    
    public static float Divide(float dividen, float divisor){
        float quotient;
        
        quotient= dividen/divisor;
        
        return quotient;
        
        
    }
}



