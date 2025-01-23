# Feature Request
* There are no asynchronous callbacks in <a href="https://bun.sh/docs/api/ffi#function-pointers">Bun FFI</a>.

# Requirements
* Docker / 4GB RAM
* OS: MacOS, Linux or Windows with WSL2

Clone repository:
```
git clone https://github.com/taronsarkisyan/bun-ffi-async-callback.git
cd bun-ffi-async-callback
```
Install Docker:
```
docker compose up -d
```

Enter container:
```
docker ps
docker exec -it <CONTAINER_ID> bash
```

Build C++ script
```
make build
```

Run Bun:
```
yarn start
```