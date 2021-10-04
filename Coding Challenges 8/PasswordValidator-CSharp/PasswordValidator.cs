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
    }
}