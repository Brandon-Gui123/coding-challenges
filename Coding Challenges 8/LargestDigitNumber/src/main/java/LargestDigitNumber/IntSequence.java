package LargestDigitNumber;

import java.util.ArrayList;

public class IntSequence
{
    private ArrayList<Integer> m_numbers;

    public IntSequence()
    {
        m_numbers = new ArrayList<>();
    }

    public int get(int index)
    {
        return m_numbers.get(index);
    }

    public int size()
    {
        return m_numbers.size();
    }

    public int sum()
    {
        int sum = 0;
        for (int number : m_numbers)
        {
            sum += number;
        }
        return sum;
    }

    public void add(int number)
    {
        m_numbers.add(number);
    }

    @Override
    public String toString()
    {
        var stringBuilder = new StringBuilder(m_numbers.size());

        for (int number : m_numbers)
        {
            stringBuilder.append(number);
        }

        return stringBuilder.toString();
    }
}
