/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ec.edu.espe.exercise;

import static ec.edu.espe.exercise.Exercise.Multiplication;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Andres Garcia
 */
public class ExerciseTest {
 

    @Test
    public void testMultiplication() {
   
        int factor1=3;
        int factor2=3;
        int expResult=9;
         int result= Multiplication(factor1,factor2);
         assertEquals(expResult, result);
    }

       @Test
    public void testMultiplicationNegative() {
  
        int factor1=-3;
        int factor2=3;
        int expResult=-9;
         int result= Multiplication(factor1,factor2);
         assertEquals(expResult, result);
    }
       @Test
    public void testMultiplicationTwoNegatives() {
      
        int factor1=-5;
        int factor2=-5;
        int expResult=25;
         int result= Multiplication(factor1,factor2);
         assertEquals(expResult, result);
    }
       @Test
    public void testMultiplicationTwoPositives() {
        
        int factor1=10;
        int factor2=10;
        int expResult=100;
         int result= Multiplication(factor1,factor2);
         assertEquals(expResult, result);
    }
       @Test
    public void testMultiplicationCero() {
      
        int factor1=0;
        int factor2=0;
        int expResult=0;
         int result= Multiplication(factor1,factor2);
         assertEquals(expResult, result);
    }
       @Test
    public void testMultiplicationOnePositiveOneNegative() {
       
        int factor1=10;
        int factor2=-10;
        int expResult=-100;
         int result= Multiplication(factor1,factor2);
         assertEquals(expResult, result);
    }
       @Test
    public void testMultiplicationTwoHighNumbers() {
        System.out.println("multiplication");
        int factor1=100;
        int factor2=100;
        int expResult=10000;
         int result= Multiplication(factor1,factor2);
         assertEquals(expResult, result);
    }
       @Test
    public void testMultiplicationOneNumberToCero() {
        System.out.println("multiplication");
        int factor1=3;
        int factor2=0;
        int expResult=0;
         int result= Multiplication(factor1,factor2);
         assertEquals(expResult, result);
    }
       @Test
    public void testMultiplicationOneBigNumberToNegative() {
        System.out.println("multiplication");
        int factor1=800;
        int factor2=-500;
        int expResult=-400000;
         int result= Multiplication(factor1,factor2);
         assertEquals(expResult, result);
    }
       @Test
    public void testMultiplicationAsAParameter() {
        System.out.println("multiplication");
        int factor1='1';
        int factor2='3';
        int expResult=3;
         int result= Multiplication(factor1,factor2);
         assertEquals(expResult, result);
    }

    
  
}
