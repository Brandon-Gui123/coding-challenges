namespace PasswordValidator_CSharp
{
    public class PasswordValidator
    {
        private string m_password;
        private bool m_currentResult;

        public PasswordValidator(string password)
        {
            m_password = password;

            // so that first-time evaluations will always be
            // executed and not short-circuited by the conditional AND
            // operator
            m_currentResult = true;
        }
    
        public PasswordValidator HaveAtLeastLength(int length)
        {
            m_currentResult = m_currentResult && m_password.Length >= length;
            return this;
        }
    
        public PasswordValidator ContainUppercaseChars()
        {
            if (!m_currentResult)
                return this;

            bool containsUppercase = false;

            foreach (var passwordChar in m_password)
            {
                if (char.IsUpper(passwordChar))
                {
                    containsUppercase = true;
                    break;
                }
            }

            m_currentResult = containsUppercase;
            return this;
        }

        public PasswordValidator ContainLowercaseChars()
        {
            if (!m_currentResult)
                return this;
            
            bool containsLowercase = false;

            foreach (var passwordChar in m_password)
            {
                if (char.IsLower(passwordChar))
                {
                    containsLowercase = true;
                    break;
                }
            }

            m_currentResult = containsLowercase;
            return this;
        }

        public PasswordValidator ContainNumbers()
        {
            if (!m_currentResult)
                return this;
            
            bool containsNumbers = false;
            foreach (var passwordChar in m_password)
            {
                if (char.IsDigit(passwordChar))
                {
                    containsNumbers = true;
                    break;
                }
            }

            m_currentResult = containsNumbers;
            return this;
        }

        public static implicit operator bool(PasswordValidator validator)
        {
            return validator.m_currentResult;
        }
    }
}