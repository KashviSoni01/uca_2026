function* calc(initialValue) {
    let result = initialValue;

    while (true) {
        const input = yield result;

        if (
            !input ||
            !["add", "subtract", "multiply", "divide"].includes(input.operation) ||
            typeof input.value !== "number"
        ) {
            yield "Invalid input";
            continue;
        }

        switch (input.operation) {
            case "add":
                result += input.value;
                break;

            case "subtract":
                result -= input.value;
                break;

            case "multiply":
                result *= input.value;
                break;

            case "divide":
                if (input.value === 0) {
                    yield "Cannot divide by zero";
                    continue;
                }
                result /= input.value;
                break;
        }

        yield result;
    }
}
