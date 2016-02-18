/**
 * HW2 Part 2 - Coding with bitwise operators
 *
 * @author [Your name here or you will lose points!!!]
 * 
 * *** NOTE: The rules are different for each java file! ***
 * 
 * The only things you are allowed to use in your code are the following:
 *	   - The bitwise operators |, &, ~, ^, <<, >>
 *     - Increment and Decrement (++ and --).
 *         - You may also add or subtract 1 from a number, but it must be only 1.
 *     - Boolean operators ||, &&, and !, which are only allowed in if-statements.
 *     - Conditional statements (if, if-else, switch-case, ? :).
 *         - However, you may only handle up to two cases.
 *         - You may only use up to 2 if/else-if statements.
 *     - Equality comparisons (==, !=, <=, >=, <, >).
 *     - The assignment operator (of course).
 *
 * You are not allowed to use anything not mentioned above. This includes the following,
 * but is not an exhaustive list:
 *     - Multiplication or Division
 *     - Addition or Subtraction with numbers other than 1.
 *     - Iteration (for/while/do while) in functions other than toString.
 *     - The unsigned right shift operator >>> (C does not provide this operator).
 *     - Modulus (%).
 *     - Any functions found in Java libraries (especially the Math library).
 *         - Example: Math.pow, Integer.bitCount, etc.
 *     - Casting (you should not have cast anywhere!)
 *     - Switch-case ban, you may not use more than 2 if-statements, or two
 *       case-statements using switch. (see the next point)
 *     - Your code should be concise and simple. None of these functions should be more
 *       than about 5-7 lines of code. If your code is any longer than this, then you are
 *       doing it wrong or inefficiently.
 *
 * Remember that for this assignment, All bit masks must be written in hexadecimal.
 * This is the convention for masks and makes it much easier for the programmer to
 * understand the code. If you write a mask in any other base you will lose points.
 *
 * All of these functions accept ints as parameters because if you pass in a number
 * (which is of type int by default) into a function accepting a byte, then the Java
 * compiler will complain even if the number would fit into that type.
 *    
 * Now, keep in mind the return value is also an int. Please read the comments about how
 * many significant bits to return and make sure that the other bits are not set or else
 * you will not get any points for that test case.
 * i.e if I say to return 6 bits and you return 0xFFFFFFFF, you will lose points.
 *
 * You will only have to worry about the cases we mentioned in the method descriptions.
 *
 * Definitions of types:
 * nibble (nybble) - 4 bits
 * byte - 8 bits
 * short - 16 bits
 * int - 32 bits
 */
public class HW2Operations
{
	/**
	 * Set a 4-bit nibble in an int.
	 * 
	 * Ints are made of eight nibbles, numbered like so:
	 *   7777 6666 5555 4444 3333 2222 1111 0000
	 *
	 * For a graphical representation of this:
	 *   1 1 1 1 1 1                 
	 *   5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 
	 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	 *  |Nibble3|Nibble2|Nibble1|Nibble0|
	 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	 * 
	 * Examples:
	 *     setNibble(0xAAA5, 0x1, 0); // => 0xAAA1
	 *     setNibble(0x56B2, 0xF, 3); // => 0xF6B2
	 * 
	 * @param num The int that will be modified.
	 * @param nibble The nibble to insert into the integer.
	 * @param which Selects which nibble to modify - 0 for least-significant nibble.
	 *            
	 * @return The modified int.
	 */
	public static int setNibble(int num, int nibble, int which)
	{
		return 0;
	}
	
	/**
	 * Get a short from an int.
	 * 
	 * Examples: 
	 *     getShort(0x56781234, 0); // => 0x1234
	 *     getShort(0xFF254545, 1); // => 0xFF25
	 * 
	 * @param num The int to get a short from.
	 * @param which Determines which short gets returned - 0 for least-significant short.
	 *            
	 * @return A short corresponding to the "which" parameter from num.
	 */
	public static int getShort(int num, int which)
	{
		return 0;
	}

	/**
	 * Pack 4 nibbles into a short.
	 * 
	 * Nibbles are 4bits. 2 nibbles make a byte. 4 nibbles make a short.
	 *
	 * The nibbles should be placed consecutively in the 16 bit short in the order
	 * specified by the parameters.
	 * 
	 * Example:
	 *     pack(0x1, 0x2, 0x3, 0x4); // => 0x1234
	 *     pack(0xB, 0xE, 0xE, 0xF); // => 0xBEEF
	 * 
	 * @param n1 Most significant nibble (will always be a 4-bit number).
	 * @param n2 2nd nibble (will always be a 4-bit number).
	 * @param n3 3rd nibble (will always be a 4-bit number).
	 * @param n4 4rd nibble (will always be a 4-bit number).
	 *            
	 * @return a 16-bit value formatted like so: n1n2n3n4
	 */
	public static int pack(int n1, int n2, int n3, int n4)
	{
		return 0;
	}
	
	/**
	 * Take the absolute value of an n-bit number.
	 * 
	 * Examples:
	 *     abs(0x00001234, 16); // => 0x00001234
	 *     abs(0x00001234, 13); // => 0x00000DCC
	 * 
	 * Note: We will only pass in values 1 to 31 for n.
	 * 
	 * @param num An n-bit 2's complement number.
	 * @param n The bit length of the number.
	 * @return The n-bit absolute value of num.
	 */
	public static int abs(int num, int n)
	{
		return 0;
	}

	/**
	 * NOTE: For this method, you may only use &, |, and ~.
	 *
	 * Perform an exclusive-or on two 32-bit ints.
	 *
	 * Examples:
	 *     xor(0xFF00FF00, 0x00FF00FF); // => 0xFFFFFFFF
	 *     xor(0x12345678, 0x87654321); // => 0x95511559
	 * 
	 * @param num1 An int
	 * @param num2 Another int
	 *
	 * @return num1 ^ num2
	 */
	public static int xor(int num1, int num2)
	{
		return 0;
	}
	
	/**
	 * Return true if the given number is a power of 2.
	 * 
	 * Examples:
	 *     powerOf2(1024); // => true
	 *     powerOf2(23);   // => false
	 *
	 * Note: Make sure you handle ALL the cases!
	 *    Hint: 0x80000000 is not a power of 2 (remember 2's complement and signed integers)
	 * 
	 * @param Num a 32-bit int. Since this is an int, it is SIGNED!
	 * @return true if num is a power of 2.
	 */
	public static boolean powerOf2(int num)
	{
		return false;
	}
}
