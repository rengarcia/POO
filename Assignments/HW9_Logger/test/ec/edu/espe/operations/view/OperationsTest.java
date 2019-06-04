/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ec.edu.espe.operations.view;

import ec.edu.espe.operations.controler.Operations;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Alan Bermudez
 */
public class OperationsTest {
    
    public OperationsTest() {
    }

    

    
    /**
     * Test of multiplication method, of class Operations.
     */
    @Test
    public void testMultiplicationCeroTimesCero() {
        int factor1=0;
        int factor2=0;
        int actualResult=Operations.multiply(factor1, factor2);
        int expectedResult=0;
        assertEquals(expectedResult, actualResult);
    }
    @Test
    public void testMultiplicationNegative() {
        int factor1=-5;
        int factor2=-5;
        int actualResult=Operations.multiply(factor1, factor2);
        int expectedResult=25;
        assertEquals(expectedResult, actualResult);
    }
    @Test
    public void testMultiplicationCharacterTimesCharacter() {
        int factor1='b';
        int factor2='a';
        int actualResult=Operations.multiply(factor1, factor2);
        int expectedResult=-1;
        assertEquals(expectedResult, actualResult);
    }
    @Test
    public void testMultiplicationBigNumbers() {
        int factor1=5000;
        int factor2=5000;
        int actualResult=Operations.multiply(factor1, factor2);
        int expectedResult=25000000;
        assertEquals(expectedResult, actualResult);
    }
    @Test
    public void testMultiplicationNegativeBigNumbers() {
        int factor1=-5000;
        int factor2=-5000;
        int actualResult=Operations.multiply(factor1, factor2);
        int expectedResult=25000000;
        assertEquals(expectedResult, actualResult);
    }
    
    @Test
    public void testMultiplication() {
        int factor1=5;
        int factor2=5;
        int actualResult=Operations.multiply(factor1, factor2);
        int expectedResult=25;
        assertEquals(expectedResult, actualResult);
    }
    @Test
    public void testMultiplicationCeroTimesNegative() {
        int factor1=0;
        int factor2=-5;
        int actualResult=Operations.multiply(factor1, factor2);
        int expectedResult=0;
        assertEquals(expectedResult, actualResult);
    }
    @Test
    public void testMultiplicationNegtiveTimesPositive() {
        int factor1=-5;
        int factor2=5;
        int actualResult=Operations.multiply(factor1, factor2);
        int expectedResult=-25;
        assertEquals(expectedResult, actualResult);
    }
    @Test
    public void testMultiplicationCharacterTimesNumber() {
        int factor1='1';
        int factor2=3;
        int actualResult=Operations.multiply(factor1, factor2);
        int expectedResult=3;
        assertEquals(expectedResult, actualResult);
    }
    @Test
    public void testMultiplicationCharacterTimesCero() {
        int factor1='1';
        int factor2=0;
        int actualResult=Operations.multiply(factor1, factor2);
        int expectedResult=0;
        assertEquals(expectedResult, actualResult);
    }
    
    
    
    
    
    
}
