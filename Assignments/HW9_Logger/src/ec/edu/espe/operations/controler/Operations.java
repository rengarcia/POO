/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ec.edu.espe.operations.controler;

import java.util.Scanner;

/**
 *
 * @author Andres Garcia
 */
public class Operations {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int factor1;
        int factor2;
        int result;
        float dividend;
        float divider;
        System.out.println("Enter the first number: ");
        factor1=scan.nextInt();
        System.out.println("Enter the second number: ");
        factor2=scan.nextInt();
        result=multiply(factor1, factor2);
        System.out.println("The result of " + factor1 + " times " 
                + factor2 + " is " + result);
        System.out.println("Enter the first number: ");
        dividend=scan.nextFloat();
        System.out.println("Enter the second number: ");
        divider=scan.nextFloat();
        divide(dividend, divider);
    }
    
    
    
    public static void divide(float dividend, float divider){
        float quocient;
        quocient=dividend/divider;
        System.out.println("The quocient between "+ dividend +
                " and " + divider + " is " +quocient);
        
    }
    
    public static int multiply(int factor1, int factor2){
        int result=0;
        int factor1Aux=factor1;
        int factor2Aux=factor2;
        
        if(factor1<0)
            factor1Aux*=-1;
        if(factor2<0)
            factor2Aux*=-1;
        for(int i=0;i<factor2Aux;i++){
            result+=factor1Aux;
        }
        if(factor1<0)
            result*=-1;
        if(factor2<0)
            result*=-1;
        return result;
        
    }
        
        
        
    }
