const { Command } = require('commander');
const fs = require('fs');
const program = new Command();
program.command('add').description('Add a new task')
    .option('-t, --title <string>', 'Task title')
    .option('-d, --date <string>', 'Date of the task')
    .action((options) => { 
        const dateString = fs.readFileSync("./data.json", "utf-8");
        const data = JSON.parse(dateString);
        const newTask = {
            id: data.length + 1,
            title: options.title,
        }
        data.push(newTask);
        fs.writeFileSync("./data.json", JSON.stringify(data, null, 2));
        console.log("Task added successfully");
    });
program.command('list').description('List all tasks')
    .option('-l, --list', 'List all tasks')
    .action(() => {
        const dateString = fs.readFileSync("./data.json", "utf-8");
        const data = JSON.parse(dateString);
        data.forEach((task, index) => {
            console.log(`${index + 1}-${task.title}`);
        });
    
    });


program.command('edit').description('Edit a task').
    option('-i, --id <number>', 'Task ID')
    .option('-t, --title <string>', 'Task title')
    .option('-d, --date <string>', 'Task date')
    .action(options => {
        const dateString = fs.readFileSync("./data.json", "utf-8");
        const data = JSON.parse(dateString);
        const taskIndex = data.findIndex(task => task.id == options.id);
        if (taskIndex !== -1) {
            data[taskIndex].title = options.title;
            fs.writeFileSync("./data.json", JSON.stringify(data, null, 2));
            console.log("Task updated successfully");
        }else {
            console.log("Task not found");
        }
    })

program.command('delete').description('Delete a task')
    .option('-i, --id <number>', 'Task ID')
    .action(options => {
        const dateString = fs.readFileSync("./data.json", "utf-8");
        const data = JSON.parse(dateString);
        const taskIndex = data.findIndex(task => task.id == options.id);
        if (taskIndex !== -1) {
            data.splice(taskIndex, 1);
            fs.writeFileSync("./data.json", JSON.stringify(data, null, 2));
            console.log("Task deleted successfully");
        }else {
            console.log("Task not found");
        }
    })


program.parse(process.argv);