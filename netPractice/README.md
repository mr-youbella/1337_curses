# netPractice

Ten saved network configurations, with the browser-based 42 simulator used to work through them.

[Repository](../README.md) · **IPv4 / subnetting / routing** · **Score: 100**

## What is in this project

Unlike the compiled projects in this repository, netPractice is a collection of configuration exercises. The JSON exports in [config_files/](config_files/) record interface addresses, subnet masks, routes, and gateways for levels 1 through 10. Empty objects in an export are part of the saved configuration format; the files do not contain the entire simulator topology.

The exercises involve checking which interfaces share a subnet, choosing valid host addresses, and finding a route through hosts, switches, routers, and an Internet node. Later levels combine multiple subnets and routing tables.

## Open the simulator

No compilation or package installation is required. Open [net_practice/index.html](net_practice/index.html) in a browser. On macOS, from this directory:

```bash
open net_practice/index.html
```

Enter the intranet login to start the level sequence. The bundled introduction also offers a defense mode when the login is left empty: three random levels from 6 to 10 in 15 minutes. The simulator uses browser local storage for its login and session state.

Use the interface to edit the network, check its goals, and export a configuration. The existing `config_files/level1.json` through `level10.json` can be inspected alongside the corresponding levels; opening the introduction does not automatically apply those exports.

## Repository layout

```text
config_files/     Saved JSON exports for levels 1–10
net_practice/     Supplied HTML/CSS/JavaScript simulator
  index.html      Entry page
  js/             Topologies, simulation, validation, and export code
  License         Terms supplied with the simulator
```

The simulator is provided by 42; it is not my implementation of a network engine. Its [license notice](net_practice/License) is retained with the files.

## Checking a configuration

Work through the simulator's connectivity goals. For each failed path, compare the interface's address and mask, the directly reachable subnet, the selected route, and the next-hop gateway. Recheck both directions of a connection before exporting a level.

The saved files are configuration artifacts, not a separate automated test suite.

[Project subject](../Subjects/netPractice.subject.pdf) · [Back to 1337 Curses](../README.md)
