# How to setup environment variables

We use environment variables heavily in our projects. It allows us to have personalized configurations, but it also makes it easy to deploy our projects without having to store sensitive values in our codebase.



## A short introduction to the config file

A config file in Vapor (`Config/someconfig.json`) is basically a JSON file with keys and values, like this:



```json
{
    "name": "my project",
    "mySecretApiKey": "topsecretapikey"
}
```





To set the values of your config file, you have a couple of options:



### Hardcode the values into the config

```json
{
    "name": "my project",
    "mySecretApiKey": "topsecretapikey"
}
```



Hardcoding the values directly into the config means that the values goes hand in hand with the codebase. This can be convenient for values that doesn't change across environments, and for values that are not secret nor personal. In other words, if a fellow developer pulls down the codebase, it would make sense for that developer to keep those values in the config.



### Use environment variables

```json
{

    "server":"localhost:3306/"
    "username": yourusername,
    "password": yourpassword
}
```




There's one last option to set the values of the environment variables, which can be convenient in cases where you need to add some values for a specific project, but without changing the config files or changing your global set of environment variables on your machine. In this case, the config will look the same and will refer to your environment variables. To set the values, you edit the scheme of your project (using the api-template, the scheme is named `Run`), and you set any key values you might need under the section called "Environment Variables". To add a value to the environment variable used in the example above, one would simply add a row for the name `MY_API_KEY` with whatever value is needed.



## How to setup your own environment variables

You could export your variables in your `~/.bash_profile` and then let Xcode load these by adding a build phase, but there's a more convenient way which doesn't require adding build phases each time to your project. If you download and install [EnvPane](https://github.com/hschmidt/EnvPane) then you will get an extra preference pane in your System Preferences which will allow you to add environment variables. However, please note that after adding/changing a variable, Xcode needs to be restarted.

When a project is ready to be deployed, remember that environment variables also needs to be setup on the deployment environment. Have a look at Vapor Cloud's [documentation](https://docs.vapor.cloud/toolbox/managing-your-apps/#custom-environment-variables) on how to add this. Remember that some environment variables (e.g. MySQL variables) will automatically be created and set by Vapor Cloud. We have some shared credentials which can be found [here](https://github.com/nodes-projects/readme/blob/master/server-side/vapor/environment-variables.md) (please note that the link points to a private repo).
