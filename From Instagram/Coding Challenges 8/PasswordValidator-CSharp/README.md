# A Fluent Password Validator, in C\#

The coding challenge as described in the image, `PasswordValidator.jpg`, can
be solved simply by creating 4 methods, each returning a Boolean. Then, returning the conditional AND of the results from all 4 methods.

This seemed pretty simple.

But then I had an idea...

About a few weeks ago, I was toying around with [FluentAssertions](https://fluentassertions.com/) and I really loved the idea of making assertions readable.

So I'm thinking, can we provide such fluency to validate something like a password?

## Notes

I know there's a library out there called [FluentValidation](https://fluentvalidation.net/) which gives something similar to what FluentAssertions does, but for validating data.

In this project, I want to write my own validator.
