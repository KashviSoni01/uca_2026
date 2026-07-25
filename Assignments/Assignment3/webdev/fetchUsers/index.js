const worker = new Worker("worker.js");

worker.postMessage("fetchUsers");

worker.onmessage = function(event) {

    const users = event.data;

    if (!users || users.length === 0) {
        console.log("No users found");
        return;
    }

    users.forEach(user => {

        console.log(
            `${user.name} - ${user.active ? "Active" : "Inactive"}`
        );

    });

};

worker.onerror = function(error) {

    console.error("Error fetching users:", error.message);

};
