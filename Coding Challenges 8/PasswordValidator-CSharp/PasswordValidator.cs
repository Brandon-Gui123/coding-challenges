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
    
        public static implicit operator bool(PasswordValidator validator)
        {
            return validator.m_currentResult;
        }
    }
}